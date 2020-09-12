class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if (people.size() == 0)
            return 0;
        sort(people.begin(), people.end());
        int ub = people.size()-1;
        int atlimit =0;
        while(people[ub] == limit){
            ub--;
            atlimit++;
        }
        int lb = ub-1;
        while(lb >= 0 && people[lb+1]+people[lb]>limit){
            lb--;
        }
        if (lb < 0){
            //nobody can pair with anybody
            return people.size();
        }
        
             
        int i = lb, j=lb+1;
        int smaller_cantpair = 0;
        while(i>=0 && j<=ub){
            if(people[i]+people[j]<=limit){
                i--;
                j++;
                continue;
            }
            while(people[i]+people[j]>limit){
                i--;
                smaller_cantpair++;
                if (i == -1) break;
            }
            
        }
        int larger_cantpair = max(ub-j+1,0);
        
        int larger = ub-lb-larger_cantpair;
        int smaller = lb+1-smaller_cantpair;
        //now, everyone in larger can pair with someone in smaller if available
        int extra = (smaller_cantpair+i+2)/2;
        cout << atlimit << larger_cantpair << larger << extra << smaller_cantpair<<i;
        return atlimit + larger_cantpair + larger + extra;
        
        
    }
};