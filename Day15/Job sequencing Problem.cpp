class Solution{  
  public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here

        sort(Jobs.begin(), Jobs.end(),[](vector<int>& a, vector<int>& b){
                 return a[2] > b[2];
             });

        int zx = 0;

        for(auto &qw : Jobs){
            zx = max(zx, qw[1]);
        }

        vector<int> pz(zx + 1, -1);

        int kk = 0;
        int yy = 0;

        for(auto &rt : Jobs){

            int dd = rt[1];

            for(int mn = dd; mn >= 1; mn--){

                if(pz[mn] == -1){

                    pz[mn] = rt[0];
                    kk++;
                    yy += rt[2];
                    break;
                }
            }
        }

        return {kk, yy};
    } 
};