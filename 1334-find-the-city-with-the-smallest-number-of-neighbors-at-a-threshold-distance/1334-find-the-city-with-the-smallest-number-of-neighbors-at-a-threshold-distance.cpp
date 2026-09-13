class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> city(n,vector<int>(n, 1e9));
        for(auto i : edges){
            city[i[0]][i[1]] = i[2];
            city[i[1]][i[0]] = i[2];
        }
        for(int i = 0 ; i<n ;i++) city[i][i] =0;

        for(int k = 0 ; k< n;k++){
            for(int i = 0 ; i<n ;i++){
                for(int j = 0 ; j< n ; j++){
                    if(city[i][k] != 1e9  && city[k][j] != 1e9){
                        city[i][j] = min(city[i][j],city[i][k]+city[k][j]);
                    } 
                }
            }
        }


        int cityno =-1 ;
        int citycnt = 1e9;
        for(int i = 0 ; i<n ;i++){
            int cnt =0;
            for(int j = 0 ; j< n ; j++){
                if(city[i][j] <=distanceThreshold ){
                    cnt++;
                }
            }
            if(cnt <= citycnt){
                 citycnt = cnt;
                 cityno = i;
    }
        }
        return cityno;
    }
};