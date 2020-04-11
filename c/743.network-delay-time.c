/*
 * @lc app=leetcode id=743 lang=c
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (45.22%)
 * Likes:    1191
 * Dislikes: 207
 * Total Accepted:    76.2K
 * Total Submissions: 167.9K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */

// @lc code=start
#define INF 10000
void constructMap(int **times, int timesSize, int **pMap) {
    for (int i = 0; i < timesSize; i++) {
        int u, v, w;
        u = times[i][0];
        v = times[i][1];
        w = times[i][2];
        if (pMap[u - 1][v - 1] > w) {
            pMap[u - 1][v - 1] = w;
        }
    }
    return;
}

int Dijkstra(int **pMap, int *pDist, int *pFlag, int N, int K) {
    // init pMap and pDist
    for (int i = 0; i < N; i++) {
        pFlag[i] = 0;
        pDist[i] = pMap[K - 1][i];
    }
    pFlag[K - 1] = 1;

    int min_dist, tmp;
    int ret = 0;
    for (int i = 1; i < N; i++) {
        min_dist = INF;
        for (int j = 0; j < N; j++) {
            if (!pFlag[j] && pDist[j] < min_dist) {
                tmp = j;
                min_dist = pDist[j];
            }
        }
        if (min_dist == INF) return -1;
        pFlag[tmp] = 1;
        if (min_dist > ret) ret = min_dist;

        for (int j = 0; j < N; j++) {
            if (!pFlag[j]) {
                if (pDist[j] > min_dist + pMap[tmp][j]) {
                    pDist[j] = min_dist + pMap[tmp][j];
                }
            }
        }
    }
    return ret;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K){
    // allocate memory
    int **pMap = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        pMap[i] = (int *)malloc(sizeof(int) * N);
        // init map
        for (int j = 0; j < N; j++) {
            if (i == j) {
                pMap[i][j] = 0;
                continue;
            }
            pMap[i][j] = INF;
        }
    }

    constructMap(times, timesSize, pMap);

    int *pDist = (int *)malloc(sizeof(int) * N);
    int *pFlag = (int *)malloc(sizeof(int) * N);
    int result = Dijkstra(pMap, pDist, pFlag, N, K);

    // free memory
    free(pDist);
    free(pFlag);
    for (int i = 0; i < N; i++) {
        free(pMap[i]);
    }
    free(pMap);

    return result;
}

// @lc code=end

