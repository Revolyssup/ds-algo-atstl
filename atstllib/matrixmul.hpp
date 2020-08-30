#include<vector>
#define vec2d std::vector<std::vector<int>>
namespace atstl{
    //naive implementation
    //let two matrices of n cross n multiply to give a n cross n matrix
    vec2d matmul(vec2d a,vec2d b){
        int n=a.size(); //=b.size()
        int currSum;
        vec2d ans(n,std::vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                currSum=0;
                for(int k=0;k<n;k++){
                    currSum+=a[i][k]*b[k][j];
                }
                ans[i][j]=currSum;
            }
        }
        return ans;
    }


}