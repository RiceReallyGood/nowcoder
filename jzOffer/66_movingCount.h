class Solution {
public:
    int movingCount(int threshold, int rows, int cols){
        int N = rows * cols;
        bool *visited = new bool[N];
        for(int i = 0; i < N; i++) visited[i] = false;
        return dfs(threshold, N, cols, visited, 0);
    }
private:
    int dfs(int threshold, int N, int cols, bool *visited, int position){
        visited[position] = true;
        if(digitadd(position / cols, position % cols) > threshold) return 0;
        int ret = 1;
        if(position >= cols && !visited[position - cols])
            ret += dfs(threshold, N, cols, visited, position - cols);
        if(position >= 1 && !visited[position - 1])
            ret += dfs(threshold, N, cols, visited, position - 1);
        if(position < N - 1 && !visited[position + 1])
            ret += dfs(threshold, N, cols, visited, position + 1);
        if(position < N - cols && !visited[position + cols])
            ret += dfs(threshold, N, cols, visited, position + cols);
        return ret;
    }

    int digitadd(int a, int b){
        int sum = 0;
        while(a){
            sum += a % 10;
            a /= 10;
        }
        while(b){
            sum += b % 10;
            b /= 10;
        }
        return sum;
    }
};