#include <iostream>
#include <fstream>

using namespace std;
const int NUMOFMATCHES = 5;

bool programmercurrentdepartment(int preferences[NUMOFMATCHES*2][NUMOFMATCHES],int index_programmer,int department,int current_department){
    for(int i = 0; i < NUMOFMATCHES; i++){
        if(preferences[index_programmer][i] == current_department){
            return true;
        }
        if(preferences[index_programmer][i] == department){
            return false;
        }
    }
    return false;
};
void prefrences_match(int preferences[NUMOFMATCHES*2][NUMOFMATCHES])
{
    int programmer[NUMOFMATCHES] = {-1,-1,-1,-1,-1};
    bool taken_department[NUMOFMATCHES] = {};
    int free_department = 5;

    while(free_department > 0){
        int d;
        for(d=0; d<NUMOFMATCHES; d++){
            if(taken_department[d] == false){
                break;
            }
        }
        for(int i = 0; i<NUMOFMATCHES && taken_department[d]==false; i++)
        {
            int program_prefrences = preferences[d][i];
            if(programmer[program_prefrences-1]==-1){
                programmer[program_prefrences-1]= d;
                taken_department[d]= true;
                free_department--;
            }
            else{
                int current_department = programmer[program_prefrences-1];
                if(programmercurrentdepartment(preferences, program_prefrences+4, d+1, current_department+1) == false)
                {
                    programmer[program_prefrences-1]= d;
                    taken_department[d]= true;
                    taken_department[current_department]=false;
                }
            }
        }
    }
    for (int i = 0; i < NUMOFMATCHES; i++){
        for(int j=0; j < NUMOFMATCHES; j++){
            if(i==programmer[j]){
                cout << "Department #" << i+1 << " will get Programmer " << j+1 << endl; 
            }
        }
    }
};
int main()
{
    int preferences[NUMOFMATCHES*2][NUMOFMATCHES] = {-1};
    ifstream myDoc;
    myDoc.open("/home/o642f122/EECS348_ExtraCredit/matchingdata.txt'");
    if(myDoc.fail())
    {
        cout << "File was unable to be opened."; 
    }
    else{
        while(myDoc){
            for(int i = 0; i < NUMOFMATCHES; i++)
            {
                for(int j = 0; j < NUMOFMATCHES; j++)
                {
                    myDoc >> preferences[j][i];                    
                }
            }
            for(int i = 0; i < NUMOFMATCHES; i++)
            {
                for(int j = NUMOFMATCHES; j < NUMOFMATCHES*2; j++)
                {
                    myDoc >> preferences[j][i];             
                }
            }
        }
    }
    myDoc.close();

    prefrences_match(preferences);
    return 0;
}
