#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int separateYellow(vector<vector<string>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int lineCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == "yellow" && !visited[i][j]) {
                
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                bool isSeparated = true; 

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int newX = curr.first + dx;
                            int newY = curr.second + dy;

                            if (0 <= newX && newX < rows && 0 <= newY && newY < cols && !visited[newX][newY]) {
                                if (matrix[newX][newY] != "yellow") {
                                    isSeparated = false;
                                    lineCount=4; 
                                    break;
                                }
                                bool isAlreadySeparated = true;
                                for (int x = 0; x < rows; x++) {
                                    for (int y = 0; y < cols; y++) {
                                        if (matrix[x][y] == "yellow" && !visited[x][y]) {
                                            isAlreadySeparated = false;
                                            break;
                                        }
                                    }
                                }
                                if (!isAlreadySeparated) {
                                    q.push({newX, newY});
                                    visited[newX][newY] = true;
                                }
                            }
                        }
                        if (!isSeparated) {
                            break;
                        }
                    }
                }
            }
        }
    }

    return lineCount;
}

int main() {
    vector<vector<string>> matrix = {
        {"blue", "blue", "white", "blue", "blue", "yellow", "white", "white", "white"},
        {"blue", "blue", "white", "white", "blue", "yellow", "yellow", "blue", "blue"},
        {"yellow", "yellow", "yellow", "white", "white", "blue", "blue", "blue", "blue"},
        {"yellow", "white", "yellow", "white", "yellow", "white", "white", "blue", "blue"},
        {"white", "blue", "blue", "white", "white", "blue", "white", "white", "white"},
        {"blue", "blue", "white", "white", "white", "white", "white", "yellow", "white"}
    };
    int lines = separateYellow(matrix);

    cout << "Minimum lines required: " << lines << endl;

    return 0;
}
