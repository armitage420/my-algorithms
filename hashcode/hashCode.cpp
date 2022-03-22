// My CPP Template
#include <bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define in(x) cin>>(x);
#define tc() int test; cin>>test; for(int t = 1; t <= test; t++)
#define For(x, _, $) for(int x = _; x < $; x++)
#define ForC(x, _, $, Condition) for(int x = _; x < $; Condition)
#define vec(v, dt, n) vector<dt> v; for(int i =0; i < n; i++){ int c; cin>>c; v.push_back(c);}
 
typedef long long int ll;
typedef pair<int, string> pis;

const ll MOD = 1e9+7;
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
void swap(ll &x, ll &y){ll temp = x; x = y; y = temp;}

void displayOutput(vector<pair<string, vector<string>>>& op, int exProj){
    cout << exProj << "\n";

    for(auto projectContri : op){
        cout << projectContri.first << "\n";

        for(auto contributor : projectContri.second){
            cout << contributor << " ";
        }

        cout << "\n";
    }
}

void output(unordered_map<string, priority_queue<pis>>& skillmap, unordered_map<string, vector<int>>& projStats, unordered_map<string, vector<pair<string, int>>>& projSkills, priority_queue<pair<int, string>>& bestBeforeProj){
    /*
    No of Ex Proj
        Name of Proj
        contributors wrt roles in i/p file
    */

//    Try 1: add projects and contributors sequentially wihtout thinking about deadline starting from least best before day

    long days;
    int countProj = 0;

    // projName, vector of contributors
    vector<pair<string, vector<string>>> op;
    while(!bestBeforeProj.empty()){

        auto x = bestBeforeProj.top();
        int bestBefore = x.first;
        string proj = x.second;
        bestBeforeProj.pop();

// cout << "output\n" << proj << " " << bestBefore;
        // if(days > (-1 * bestBefore)){
        //     // cout << "break";
        //     break;
        // }
        days += projStats[proj][0];
        countProj++;
        vector<string> contributors;

        vector<pair<string, int>> projectskillmap = projSkills[proj];

        for(auto projectSkill : projectskillmap){
            string skill = projectSkill.first;
            int level = projectSkill.second;

            priority_queue<pis> skillOfperson = skillmap[skill];
            priority_queue<pis> skillOfperson2;

            string person1 = "";
            int level1 = -1;
            while(!skillOfperson.empty()){

                auto personLevel = skillOfperson.top();
                skillOfperson.pop();

                if(personLevel.first >= level){
                    person1 = personLevel.second;
                    level1 = personLevel.first;
                    break;
                }
                skillOfperson2.push(personLevel);
            }

            if(level1 < 0){
                break;
            }

            contributors.push_back(person1);
            
            (level >= level1) ? skillOfperson.push({++level1, person1}) : skillOfperson.push({level1, person1});

            skillmap[skill] = skillOfperson2;

        }
        if(contributors.size() == projSkills[proj].size()){
            op.push_back({proj, contributors});
        }
            
    }

    displayOutput(op, countProj);
}

void input(){
    int noOfContributors, noOfProjects;
    in(noOfContributors);
    in(noOfProjects);

    // cout << noOfContributors << " " << noOfProjects;

    unordered_map<string, priority_queue<pis>> skillmap;

    int contri = noOfContributors;
    while(contri--){
        string name;
        int n;
        
        cin >> name >> n;

        for(int i=0; i<n; i++){
            string skill;
            int level;
            cin >> skill >> level;

            skillmap[skill].push({level, name});

        }
    }

    int proj = noOfProjects;
    unordered_map<string, vector<int>> projStats;
    unordered_map<string, vector<pair<string, int>>> projSkills;

    priority_queue<pair<int, string>> bestBeforeProj;

    while(proj--){
        string projName;
        int dayscomp, scoreaward, bestbefore, noOfRoles;

        cin >> projName >> dayscomp >> scoreaward >> bestbefore >> noOfRoles;
        projStats[projName] = { dayscomp, scoreaward, bestbefore};

        bestBeforeProj.push({-bestbefore, projName});

        for(int i=0; i<noOfRoles; i++){
        string skill;
        int level;

        cin >> skill >> level;
        projSkills[projName].push_back({skill, level});
        }
    }

    output(skillmap, projStats, projSkills, bestBeforeProj);
}

int main(){
    fast;

    #ifndef ONLINE_JUDGE
    freopen("../c_collaboration.in.txt", "r", stdin);
    freopen("../C.txt", "w", stdout);
    #endif

    input();
    // testcases();
    return 0;
}


    // while(!bestBeforeProj.empty()){
    //     auto x = bestBeforeProj.top();
    //     bestBeforeProj.pop();

    //     cout << x.first << " " << x.second << "\n";
    // }


    // cout << "map\n";
    // for(auto skilly : skillmap){
    //     cout << "skill " << skilly.first;
        
    //     priority_queue<pis> q = skillmap[skilly.first];

    //     while(!q.empty()){
    //         auto x = q.top();
    //         int level = x.first;
    //         string name = x.second;

    //         q.pop();
    //         cout << "\n"<< level << " " << name << "\n";
    //     }
    