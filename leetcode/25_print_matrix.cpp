// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

//  

// 示例 1：

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：

// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//  

// 限制：

// 0 <= matrix.length <= 100
// 0 <= matrix[i].length <= 100

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &res) {
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}

// 1, 2
// 3, 4

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    int m = matrix.size();
    if (m <= 0) return vector<int>();
    int n = matrix[0].size();
    int l = 0, r = n-1, t = 0, d = m-1;
    vector<int> res;
    while (1) {
        int i = l;
        if (i >= r+1) break;
        while (i < r+1) {
            res.push_back(matrix[t][i++]);
        }
        ++t;
        i = t;
        if (i >= d+1) break;
        while (i < d+1) {
            res.push_back(matrix[i++][r]);
        }
        --r;
        i = r;
        if (i < l) break;
        while(i >= l) {
            res.push_back(matrix[d][i--]);
        }
        --d;
        i = d;
        if (i < t) break;
        while(i >= t) {
            res.push_back(matrix[i--][l]);
        }
        ++l;
        printVec(res);
    }
    return res;

}


int main() {
    int arr1[] = {1,2,3,4};
    int arr2[] = {5,6,7,8};
    int arr3[] = {9,10,11,12};
    vector<int> vec1(arr1, arr1+4);
    vector<int> vec2(arr2, arr2+4);
    vector<int> vec3(arr3, arr3+4);
    vector<vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vector<int> res;
    res = spiralOrder(vec);
    return 0;
}