class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        int i = 0; 
        int j = 0;

        while(i < Student.size() && j < Cookie.size()){

            if(Cookie[j] >= Student[i]){
                i++; 
            }

            j++; 
        }

        return i;
    }
};