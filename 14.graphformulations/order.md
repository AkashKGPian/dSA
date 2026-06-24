1. https://leetcode.com/problems/shortest-path-in-binary-matrix/description/ - bfs can visit a cell only if cell is 0 else cell is blocked - bfs 
    if cell !visited and cell!=1
        -> dist_neigh = dist_node+1; and mark visited

        cell==1 => cell is blocked and cant be visited   ==> weight is fixed and is =1  ==> bfs

2. 01BFS\1_minWallsToBeBroken.cpp - 01bfs - deque - 

        cell==# => cell is blocked but can be broken ==> cost = 0/1 depending upon the condition 
                                                                even wall can be visited
                                                                 => weight=0/1 =>01bfs

                                                                
            int edge = (arr[nx][ny]=='#') ? 1 : 0;
            if(dist[nx][ny] > dist[curr.f][curr.s]+edge){  --------> minimizing the no. of walls broken
                dist[nx][ny] = dist[curr.f][curr.s]+edge;
                if(edge==0){ 
                    dq.push_front({nx,ny});
                }else{
                    dq.push_back({nx,ny});
                }
            }
3. 01BFS\2_stateSpaceFormulation_bfs\2_minStepsReqIflessthanEqualtoKwallCanBeBrokin.cpp
            vis = vector<vector<vector<int>>>
                        (n,vector<vector<int>>
                            (m,vector<int>
                                (k+1,0)//k+1 have k as an accessible arr index as restriction wallbroken >=k
                            )
                        );
4. 01BFS\2_stateSpaceFormulation_bfs\2_contdAbovePrintingAllstepsuptillNM.cpp

5. dijkstra easy : 
    a_network delay;
    b_cheapflight
