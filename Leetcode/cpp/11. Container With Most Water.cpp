class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator left_height=height.begin();
        vector<int>::iterator right_height=height.end()-1;
        int result=0;
        // cout<<*left_height<<","<<*right_height<<endl;
        for (int i =height.size()-1;i>0;i--){
            result=max(min(*left_height,*right_height)*i,result);
            if(*left_height<*right_height)left_height++;
            else right_height--;
            // cout<<result<<endl;
        }
        return result;
    }
};
