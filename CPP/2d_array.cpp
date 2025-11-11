#include <algorithm>
#include <iostream>


using namespace std;

// ------------------ 2D ARRAY (STATIC) ------------------

void printArrayMatrix(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void transposeArrayMatrix(int arr[][3], int rows, int cols, int result[][2]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = arr[i][j];
        }
    }
}

void rotateArrayMatrix90Clockwise(int arr[][3], int rows, int cols, int result[][2]) {
    // Step 1: Transpose
    transposeArrayMatrix(arr, rows, cols, result);
    // Step 2: Reverse each row of the transposed matrix
    for (int i = 0; i < cols; i++) {
        reverse(result[i], result[i] + rows);
    }
}

// ------------------ VECTOR MATRIX ------------------

void printVectorMatrix(vector<vector<int>>& mat) {
    for (auto &row : mat) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> transposeVectorMatrix(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> trans(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans[j][i] = mat[i][j];
    return trans;
}

vector<vector<int>> rotateVectorMatrix90Clockwise(vector<vector<int>>& mat) {
    vector<vector<int>> trans = transposeVectorMatrix(mat);
    for (auto &row : trans)
        reverse(row.begin(), row.end());
    return trans;
}

// ------------------ MAIN ------------------

int main() {
    cout << "=== Using 2D Array ===\n";
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "Original matrix:\n";
    printArrayMatrix(arr, 2, 3);

    int trans[3][2];
    transposeArrayMatrix(arr, 2, 3, trans);
    cout << "Transpose:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    int rotated[3][2];
    rotateArrayMatrix90Clockwise(arr, 2, 3, rotated);
    cout << "Rotated 90° Clockwise:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << rotated[i][j] << " ";
        cout << endl;
    }

    cout << "\n=== Using vector<vector<int>> ===\n";
    vector<vector<int>> mat = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    cout << "Original matrix:\n";
    printVectorMatrix(mat);

    vector<vector<int>> tmat = transposeVectorMatrix(mat);
    cout << "Transpose:\n";
    printVectorMatrix(tmat);

    vector<vector<int>> rmat = rotateVectorMatrix90Clockwise(mat);
    cout << "Rotated 90° Clockwise:\n";
    printVectorMatrix(rmat);

    return 0;
}
