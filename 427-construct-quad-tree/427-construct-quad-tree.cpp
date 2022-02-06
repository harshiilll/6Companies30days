/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int sum(int r1, int c1, int r2, int c2, vector<vector<int>> &presum) {
        return presum[r2+1][c2+1] - presum[r1][c2+1] - presum[r2+1][c1] + presum[r1][c1];
    }

    int val(int r1, int c1, int r2, int c2, vector<vector<int>> &presum) {
        int total = sum(r1, c1, r2, c2, presum);
        int area = (r2 - r1 + 1)*(c2 - c1 + 1);

        if(total == 0) return 0;
        if(total == area) return 1;
        return -1;
    }
    
    Node* construct(int r1, int c1, int r2, int c2, vector<vector<int>> &presum) {
        int value = val(r1, c1, r2, c2, presum);
        
        if(value != -1) {
            return new Node(value, true);
        }
        
        int side = (r2 - r1 + 1) / 2;

        return new Node(false, false,
            construct(r1, c1, r2 - side, c2 - side, presum), // topLeft
            construct(r1, c1 + side, r2 - side, c2, presum), // topRight
            construct(r1 + side, c1, r2, c2 - side, presum), // bottomLeft
            construct(r1 + side, c1 + side, r2, c2, presum) // bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        int side = grid.size();

        vector<vector<int>> presum(side + 1, vector<int>(side + 1, 0));

        for(int r = 0; r < side; ++r) {
            for(int c = 0; c < side; ++c) {
                presum[r + 1][c + 1] = grid[r][c] + presum[r][c + 1] + presum[r + 1][c] - presum[r][c];
            }
        }

        return construct(0, 0, side - 1, side - 1, presum);
    }
};