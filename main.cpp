//
//  main.cpp
//  HR User
//
//  Created by Yseeva.
//

#include <iostream>
#include <string.h>
#include <fstream>

//برک ها ر از بریس دربیارم

class Menu{
    public:
    bool Registerd = false;
    int Key , REadKey;
    bool RgisteringSettings(int Key){
      // std::ifstream file;
       //file.open("key.txt");
       this->Key=Key;
      // file>>REadKey;
       if (Key=123)//Key==REadKey)
       {
        return true;
       }
       else
        return false;
    }
    int Option;
    Menu(){
        std::cout<<"------- WELCOME TO THIS PROGRAM ------- " <<'\a'<<std::endl<<std::endl<<std::endl;
       // this->Option=Choice;
        std::cout<<" I need You To enter the KEY CODE below in order to be registerd as HR user "<<std::endl;
        std::wcin>>Key;
        Registerd=RgisteringSettings(Key);
    }
    
    void ShowOptions(){
        if (Key==123)//Registerd)
        {
            //system("color fc");
            std::cout<<"****** ---------------------------- ****** "<<std::endl;
            std::cout<<"*      ::      1-Add an Item     ::      *"<<std::endl;
            std::cout<<"* - - - - - - - - - - - - - - - - - - - -*"<<std::endl;
            std::cout<<"*      ::   2-Delete an Item     ::      *"<<std::endl;
             std::cout<<"* - - - - - - - - - - - - - - - - - - - -*"<<std::endl;
            std::cout<<"*      ::     3-Edit an Item     ::      *"<<std::endl;
             std::cout<<"* - - - - - - - - - - - - - - - - - - - -*"<<std::endl;
            std::cout<<"*      ::   4-Search an Item     ::      *"<<std::endl;
             std::cout<<"* - - - - - - - - - - - - - - - - - - - -*"<<std::endl;
            std::cout<<"*      ::      5-PRINT DATA      ::      *"<<std::endl;
            std::cout<<"****** ---------------------------- ****** "<<std::endl;
            
            
        } 
        else 
        std::cout<<"SORRY I AM NOT ALLOWED TO GIVE YOU ACCESS "<<std::endl;
        
    }

};

//enum SHIFT { DAY , NIGHT};  زیادیه دیگه
enum TYPE_TIME {FULLTIME , PARTTIME , INTERN };
enum WORKINGLOCATION {COMPANY , FROMHOME};
enum GENDER {FEMALE ,MALE };
enum LEVEL { JUNIOR, INTERMEDIATE , SENIOR};
enum TYPE_YEARNING {PROJECT_ORIENTED , CONTRACT_ORIENTED };


class PersonWorking{ 
public:
    std::string FirstName , LastName ;
    int Age ;
    GENDER gndr;
    TYPE_TIME Wrk;
    WORKINGLOCATION location;
    std::string str1=std::to_string(Wrk);
    std::string str2=std::to_string(gndr);
    std::string str3=std::to_string(location);

    PersonWorking(){
        gndr=MALE;
        Wrk=FULLTIME;
        location=COMPANY;
        
    }
     void ShowDetails(){
        std::cout<<FirstName + " " + LastName + std::to_string(Age) + str1 + " "+str2+" "+str3;
    }
    
};
std::istream & operator >> (std::istream &CIN , PersonWorking &prsnworkin){
    std::cout<<"Enter firstName -> "<<'\t';
    CIN>>prsnworkin.FirstName;
    std::cout<<"Enter LastName -> "<<'\t';
    CIN>>prsnworkin.LastName;
    std::cout<<"Enter age -> "<<'\t';
    CIN>>prsnworkin.Age;
    int num1,num2,num3;
     std::cout<<"enter your gender option -> "<<'\t';
     std::cout<<"0- female     1- male "<<'\t';
     std::wcin>>num1;
     if(num1==1){
        prsnworkin.gndr=MALE;
     }
     else
       prsnworkin.gndr=FEMALE;

     std::cout<<"enter your Working Location option -> "<<'\t';
     std::cout<<"0- Company     1- From home "<<'\t';
     std::wcin>>num2;
     if(num2==0){
        prsnworkin.location=COMPANY;
     }
     else
       prsnworkin.location=FROMHOME;

     std::cout<<"enter your Working Time Type option -> "<<'\t';
     std::cout<<"0- FullTime     1- Part Time   2-Intern "<<'\t';
     std::wcin>>num3;
     if(num3==0){
        prsnworkin.Wrk=FULLTIME;
     }
     else if(num3==1){
        prsnworkin.Wrk=PARTTIME;
     }
     else
        prsnworkin.Wrk=INTERN;
    return CIN;

}
class NormalStaff: public PersonWorking{
public:
    std::string section;
    NormalStaff(){
        section="Archive";
    }
    NormalStaff *Next ;
    void ShowDetails() {
        PersonWorking::ShowDetails();
        std::cout<<section;
    }

};
std::istream & operator >> (std::istream &CIN , NormalStaff &nrmalstaff){
    PersonWorking prs;
    std::cin>>prs;
    CIN>>nrmalstaff.section;
    return CIN;
    
}
class Programmer : public PersonWorking{
public:
    int ProjectNo;
    std::string Language;
    LEVEL lvl;
    bool Interviewd = true;
    TYPE_YEARNING typeYr=PROJECT_ORIENTED;
 
    Programmer(){
        lvl=JUNIOR;
        ProjectNo=1;
    }
    //Programmer *Next;
    void ShowDetails(){
        PersonWorking::ShowDetails();
        std::string str1 =std::to_string(typeYr);
        std::string str2 = std::to_string(lvl);
        std::cout<<Language+" "+std::to_string(ProjectNo)+" "+str1+" "+str2;
        if(Interviewd)
        {
            std::cout<<"has been interviewd"<<std::endl;
        }
        else
            std::cout<<"Has not been interviewd"<<std::endl;
    }
};
std::istream & operator >> (std::istream &CIN , Programmer &prgrammer){
    PersonWorking prs;
    std::cin>>prs;
    std::cout<<"Enter project done by him/her -> "<<std::endl;
    CIN>>prgrammer.ProjectNo;
    std::cout<<"Enter the main language using -> "<<std::endl;
    CIN>>prgrammer.Language;
    std::cout<<"Has he/she been interviewd before ? (1 for yes and 0 for no) -> "<<std::endl;
    int num1,num2,num3;
    if(num1==0){
        prgrammer.Interviewd=false;

    }
    else 
        prgrammer.Interviewd=true;
    std::cout<<"Enter his/her level of coding -> "<<std::endl;
    std::cout<<"1 for junior // 2 for senior // 3 for intermediate -> "<<std::endl;
    std::cin>>num2;
     if(num2==1){
        prgrammer.lvl=JUNIOR;
    }
     else if(num2==2){
        prgrammer.lvl=SENIOR;
    }
     else
       prgrammer.lvl=INTERMEDIATE;
    std::cout<<"Enter the salary yearning type -> "<<std::endl;
    std::cout<<"1.project oriented  2.contract oriented -> "<<std::endl;
    std::cin>>num3;
    if(num3==1){
        prgrammer.typeYr=PROJECT_ORIENTED;
    }
    else 
        prgrammer.typeYr=CONTRACT_ORIENTED;
    return CIN;
    
}
class Admin : public PersonWorking {
public:
   double Share;
   bool WorkInTeam=true;
   Admin(){
   }
  // Admin *Next;
   void ShowDetails(){
    PersonWorking::ShowDetails();
    std::cout<<std::to_string(Share)<<std::endl;
    if(WorkInTeam){
        std::cout<<"is working in a team";
    }
    else
        std::cout<<"Is not working in a team";
   }
};
std::istream & operator >> (std::istream &CIN , Admin &admn){
    PersonWorking prs;
    std::cin>>prs;
    std::cout<<"Enter admin share ->"<<std::endl;
    CIN>>admn.Share;
    std::cout<<"is the admin working in a team? (0 for yes and 1 for no) ->"<<std::endl;
    int num1;
    std::cin>>num1;
    if(num1==0){
       admn.WorkInTeam=true;
    }
    else
      admn.WorkInTeam=false;
    
    return CIN;
}
class SM : public Programmer , public Admin{
public:
    std:: string currentProj;
    int teamMembers;
    SM(){

    }
    //SM *Next;
    void ShowDetails(){
        Programmer::ShowDetails();
        std::cout<<std::to_string(Share)<<std::endl;
        if(WorkInTeam){
        std::cout<<"is working in a team";
         }
        else
        std::cout<<"Is not working in a team";
    
       std::cout<<currentProj+" "+std::to_string(teamMembers);
    }

    
};
std::istream & operator >> (std::istream &CIN , SM &sm){ 
    Programmer prg;
    Admin admn;
    std::cin>>prg;
    std::cout<<"Enter admin share ->"<<std::endl;
    CIN>>admn.Share;
    std::cout<<"is the admin working in a team? (0 for yes and 1 for no) ->"<<std::endl;
    int num1;
    std::cin>>num1;
    if(num1==0){
       admn.WorkInTeam=true;
    }
    else
      admn.WorkInTeam=false;

    std::cout<<"Enter SM current project ->"<<std::endl;
    CIN>>sm.currentProj;
    std::cout<<"Enter SM team members number ->"<<std::endl;
    CIN>>sm.teamMembers;
    return CIN;
}

class DataBase : public PersonWorking{
public:
    int TechnicalExperting;
    bool OtherCompanies;
    DataBase(){

    }
    DataBase *Next;
    void ShowDetails(){
        PersonWorking::ShowDetails();
        std::cout<<std::to_string(TechnicalExperting);
        if(OtherCompanies){
            std::cout<<"this data base scientist works in other companies"<<std::endl;
        }
        else 
            std::cout<<"this data base scientist doesn't works in other companies"<<std::endl;

    }
};
std::istream & operator >> (std::istream &CIN , DataBase &dtabs){
    PersonWorking prs;
    std::cin>>prs;
    std::cout<<"enter the tchnical experience of the data base scientist ->"<<std::endl;
    CIN>>dtabs.TechnicalExperting;
    std::cout<<"does this scientist work for other companies too ? (0 for yes 1 for no) ->"<<std::endl;
    int num1;
    std::cin>>num1;
    if(num1==0){
        dtabs.OtherCompanies=true;
    }
    else 
       dtabs.OtherCompanies=false;
}

class DA : public DataBase, Admin{
public:
    
    bool LeaderShipAbilities;
    DA(){

    }
    //DA *Next;
    void ShowDetails(){
        DataBase::ShowDetails();
         std::cout<<std::to_string(Share)<<std::endl;
    if(WorkInTeam){
        std::cout<<"is working in a team";
    }
    else
        std::cout<<"Is not working in a team";
        if(LeaderShipAbilities){
            std::cout<<"they have leadership abillity "<<std::endl;

        }
        else 
           std::cout<<"they don't have leadership abillity "<<std::endl;
   
    }
};
std::istream & operator >> (std::istream &CIN , DA &da){
    DataBase dtbse;
    Admin admn;
    std::cin>>dtbse;
    PersonWorking prs;
    std::cin>>prs;
    std::cout<<"Enter admin share ->"<<std::endl;
    CIN>>admn.Share;
    std::cout<<"is the admin working in a team? (0 for yes and 1 for no) ->"<<std::endl;
    int num1,num2;
    std::cin>>num1;
    if(num1==0){
       admn.WorkInTeam=true;
    }
    else
      admn.WorkInTeam=false;
    std::cout<<"Does he/she has the leadership ability ? (0 for yes and 1 for no ) ->"<<std::endl;
    if(num1==0){
        da.LeaderShipAbilities=true;
    }
    else 
        da.LeaderShipAbilities=false;
    return CIN;
    
}
class Testing : public PersonWorking{
public:
    std::string TestInQueue;
    Testing(){

    }
    //Testing *Next;
    void ShowDetails(){
        PersonWorking::ShowDetails();
        std::cout<<TestInQueue<<std::endl;
    }
};
std::istream & operator >> (std::istream &CIN , Testing &tst){ 
    PersonWorking prs;
    std::cin>>prs;
    std::cout<<"What is the project now working on ?"<<std::endl;
    CIN>>tst.TestInQueue;
    return CIN;
}


template <class temp1>
 void AddFunction(temp1 (*ClassArr) , int size){
    std::cout<<"     first choose what part he/she works in -> "<<std::endl;
    std::cout<<" -------------------------------------------------"<<std::endl;
    std::cout<<"1- Normal Staff        || 2- Programmer     || 3-Scrum Master "<<std::endl;
    std::cout<<"4- Data Base Scientist || 5-Data Base Admin || 6-Testing Admin "<<std::endl;
    int option;
    std::cin>>option;
    switch (option)
    {
    case 1: //it is a normal staff
    {   NormalStaff ClassArr[size+1];
        std::cin>>ClassArr[size+1];
        break;
    }
    case 2: //it is a programmer
    {   
        Programmer ClassArr[size+1];
        std::cin>>ClassArr[size+1];
        break;
       }
    
    case 3: //it is a Scrum master
       {   
        SM ClassArr[size+1];
        std::cin>>ClassArr[size+1];
        break;
       }
       case 4:
        {     //it is a data base
        DataBase ClassArr[size+1];
        std::cin>>ClassArr[size+1];
        break;
       }
       case 5:{
                //it is a data base admin
        DA ClassArr[size+1];
        std::cin>>ClassArr[size+1];
        break;
       }

       case 6:  //it is a testing admin
        {   
        Testing ClassArr[size+1];
       std::cin>>ClassArr[size+1];
        break;
       }
       
    }
 } 
 
template< class temp2 >
 void DeleteFunction(temp2 (*ClassArr) , int size ){
    std::cout<<"     first choose what part he/she works in -> "<<std::endl;
    std::cout<<" -------------------------------------------------"<<std::endl;
    std::cout<<"1- Normal Staff        || 2- Programmer     || 3-Scrum Master "<<std::endl;
    std::cout<<"4- Data Base Scientist || 5-Data Base Admin || 6-Testing Admin "<<std::endl;
    int option;
    std::wcin>>option;
    std::cout<<"Now enter the name of person you want to delete his/her data"<<std::endl;
    
    std::string itsName;
    std::cin>>itsName;
    switch (Option)
    {
    
    case 1: //it is a normal staff
    {   NormalStaff ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              delete ClassArr[i];
            }
            else 
            i++;

        }
        
    }
    break;

    case 2: //it is a programmer
    {   
        Programmer ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              delete ClassArr[i];
            }
            else 
            i++;
        }
        break;
       }
    
    case 3: //it is a Scrum master
       {   
        SM ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              delete ClassArr[i];
            }
            else 
            i++;

        }
        break;
       }
       case 4:
        {     //it is a data base
        DataBase ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              delete ClassArr[i];
            }
            else 
            i++;

        }
        break;
       }
       case 5:{
                //it is a data base admin
        DA ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
               delete ClassArr[i];
            }
            else 
            i++;

        }
        break;
       }

       case 6:  //it is a testing admin
        {   
        Testing ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              delete ClassArr[i];
            }
            else 
            i++;

        }
        break;
       }
       
    } 
 }
//void deleteArrayOb(temp2 *ClassArr , int size)
    

template <class temp3 >
 void EditFunction ( temp3 (*ClassArr) , int size){
    std::cout<<"     first choose what part he/she works in -> "<<std::endl;
    std::cout<<" -------------------------------------------------"<<std::endl;
    std::cout<<"1- Normal Staff        || 2- Programmer     || 3-Scrum Master "<<std::endl;
    std::cout<<"4- Data Base Scientist || 5-Data Base Admin || 6-Testing Admin "<<std::endl;
    int option;
    std::cin>>option;
    std::cout<<"Now enter the fullname of person you want to delete his/her data withput space"<<std::endl;
     switch (option)
    {
        std::string itsName;
        std::cin>>itsName;
    case 1: //it is a normal staff
    {   NormalStaff ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              delete ClassArr[i];
            }
            else 
            i++;
        
        break;
    }
    }
    case 2: //it is a programmer
    {   
        Programmer ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
                std::cout<<"The old data : "<<std::endl;
                ClassArr->ShowDetails();
                std::cout<<"Enter new Data : "<<std::endl;
                std::cin>>ClassArr[i];
                std::cout<<"Now the new information is :"<<std::endl;
                ClassArr[i].ShowDetails();
            }
            else 
            i++;
        break;
       }
    }
    case 3: //it is a Scrum master
       {   
        SM ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
                std::cout<<"The old data : "<<std::endl;
                ClassArr->ShowDetails();
                std::cout<<"Enter new Data : "<<std::endl;
                std::cin>>ClassArr[i];
                std::cout<<"Now the new information is :"<<std::endl;
                ClassArr[i].ShowDetails();
            }
            else 
            i++;
        break;
       }
     }
       case 4:
        {     //it is a data base
        DataBase ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
                std::cout<<"The old data : "<<std::endl;
                ClassArr->ShowDetails();
                std::cout<<"Enter new Data : "<<std::endl;
                std::cin>>ClassArr[i];
                std::cout<<"Now the new information is :"<<std::endl;
                ClassArr[i].ShowDetails();
            }
            else 
            i++;
        
       }
       break;
        }
       case 5:{
                //it is a data base admin
        DA ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
                std::cout<<"The old data : "<<std::endl;
                ClassArr->ShowDetails();
                std::cout<<"Enter new Data : "<<std::endl;
                std::cin>>ClassArr[i];
                std::cout<<"Now the new information is :"<<std::endl;
                ClassArr[i].ShowDetails();
            }
            else 
            i++;
        break;
       }
       }

       case 6:  //it is a testing admin
        {   
        Testing ClassArr[size];
       for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
                std::cout<<"The old data : "<<std::endl;
                ClassArr->ShowDetails();
                std::cout<<"Enter new Data : "<<std::endl;
                std::cin>>ClassArr[i];
                std::cout<<"Now the new information is :"<<std::endl;
                ClassArr[i].ShowDetails();
            }
            else 
            i++;
        break;
       }
        }
       
    }
 } 
 
template <class temp4>
void SearchFunction( temp4 (*ClassArr) , int size){
    std::cout<<"     first choose what part he/she works in -> "<<std::endl;
    std::cout<<" -------------------------------------------------"<<std::endl;
    std::cout<<"1- Normal Staff        || 2- Programmer     || 3-Scrum Master "<<std::endl;
    std::cout<<"4- Data Base Scientist || 5-Data Base Admin || 6-Testing Admin "<<std::endl;
    int option;
    std::wcin>>option;
    std::cout<<"Now enter the fullname of person you want to delete his/her data withput space"<<std::endl;
    
    switch (Option)
    {
    std::string itsName;
    std::cin>>itsName;
    case 1: //it is a normal staff
    {   NormalStaff ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              ClassArr[i].ShowDetails();
            }
            else 
            i++;

        }
        break;
    }
    case 2: //it is a programmer
    {   
        Programmer ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              ClassArr[i].ShowDetails();
            }
            else 
            i++;
        }
        break;
       }
    
    case 3: //it is a Scrum master
       {   
        SM ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              ClassArr[i].ShowDetails();
            }
            else 
            i++;
        }
        break;
       }
       case 4:
        {     //it is a data base
        DataBase ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
                ClassArr[i].ShowDetails();
            }
            else 
            i++;

        }
        break;
       }
       case 5:{
                //it is a data base admin
        DA ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
               ClassArr[i].ShowDetails();
            }
            else 
            i++;

        }
        break;
       }

       case 6:  //it is a testing admin
        {   
        Testing ClassArr[size];
        for(int i=0 ; i<size  ; i++){
            if((ClassArr[i].FirstName+ClassArr[i].LastName) ==itsName ){
              ClassArr[i].ShowDetails();
            }
            else 
            i++;

        }
        break;
       }
       
    } 
}
  
class File
{
    template <class T>

    void static save(T o)
    {
        std::ofstream filewriter;
        filewriter.open(path,std::ios::app);
        filewriter << o.showDetails() << std::endl;
        filewriter.close();
    }
};
template <class Const>
int main(){
    Menu mn ;
    mn.ShowOptions();
    std::wcin>>mn.Option;
    Const arr[4];
    switch (mn.Option)
    {
    case 1://add
      AddFunction(arr , 4);
        break;
    case 2 : //delete
       DeleteFunction(arr , 4);
        break;
    case 3 : //edit
       EditFunction(arr , 4);
        break;
    case 4: //search
       SearchFunction(arr , 4);
        break;
    case 5 : //print
       File file;
        break;
    }

    


    return 0;
}
