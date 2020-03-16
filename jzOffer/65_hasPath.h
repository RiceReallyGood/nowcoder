#include <cstring>

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
        if(str[0] == '\0') return false;
        int N = rows * cols;
        bool *visited = new bool[N];
        for(int i = 0; i < N; i++) visited[i] = false;
        for(int i = 0; i < N; i++)
            if(matrix[i] == str[0] && dfs(matrix, visited, N, cols, i, str, 0))
                return true;
        return false;
    }

private:
    bool dfs(char* matrix, bool* visited, int N, int cols, int position,char* str, int index){
        if(str[index + 1] == '\0') return true;
        visited[position] = true;
        if(position >= cols &&  !visited[position - cols] && matrix[position - cols] == str[index + 1] 
                            && dfs(matrix, visited, N, cols, position - cols, str, index + 1))
            return true;
        if(position >= 1 && !visited[position - 1] && matrix[position - 1] == str[index + 1]
                         && dfs(matrix, visited, N, cols, position - 1, str, index + 1))
            return true;
        if(position < N - 1 && !visited[position + 1] && matrix[position + 1] == str[index + 1]
                            && dfs(matrix, visited, N, cols, position + 1, str, index + 1))
            return true;
        if(position < N - cols && !visited[position + cols] && matrix[position + cols] == str[index + 1]
                               && dfs(matrix, visited, N, cols, position + cols, str, index + 1))
            return true;
        visited[position] = false;
        return false;
    }
};