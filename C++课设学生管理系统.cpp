#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;
#define Max 50;/*最大人数*/
/*学生类，用于返回信息，设置数据*/
class Student{
    public:
    Student(){};
    Student(string name,string id,string sex,string cla,double english,double math,double chinese):Name(name),ID(id),Sex(sex),Class(cla),English(english),Math(math),Chinese(chinese){};
    void set_Name(string name){
        this->Name=name;
    }
    void set_ID(string id){
        this->ID=id;
    }
    void set_Sex(string sex){
        this->Sex=sex;
    }
    void set_Class(string cla){
        this->Class=cla;
    }
    void set_English(double english){
        this->English=english;
    }
    void set_Math(double math){
        this->Math=math;
    }
    void set_Chinese(double chinese){
        this->Chinese=chinese;
    }
    void set_Row(int row){
        this->Row=row;
    }
    double Sum_sum(){
         double sum=English+Chinese+Math;
         this->Sum=sum;
    }
    double Average_average(){
        Average=(Chinese+Math+English)/3;
    }
    const string &get_Name() const{
        return Name;
    }
    const string &get_ID() const{
        return ID;
    }
    const string &get_Sex() const{
        return Sex;
    }
    const string &get_Class() const{
        return Class;
    }
    double get_Math() const{
        return Math;
    }
    double get_English() const{
        return English;
    }
    double get_Chinese() const{
        return Chinese;
    }
    double get_Sum(){
        return (English+Chinese+Math);
    }
    int get_Row(){
        return Row;
    }
    int get_Average(){
        return (English+Math+Chinese)/3;
    }
    private:
    string Name;
    string ID;
    string Sex;
    string Class;
    double English=0;
    double Math=0;
    double Chinese=0;
    double Sum=Chinese+Math+English;
    double Average=0;
    int Row=0;
};
/*系统功能类*/
class SystemFunction:public Student{
    private:
    Student students[1000];/*学生类数组*/
    string studentId;
    int number=0;
    /*删除功能*/
    bool _delete(int i){
        char judge;
        cin>>judge;
        switch(judge){
            case 'Y':
            case 'y':
            for(int j=i;j<number;j++){
                if(j==(number+1)){
                    Student student;
                    students[j]=student;
                }else{
                    students[j]=students[j+1];
                }
            }
            number--;
            return true;
        defalt:
            cout<<"输入错误或删除失败";
            return false;
        }
    }
    /*修改功能*/
    void modify(int i){
        string inform[]={"姓名","学号","性别","班级","英语","数学","语文"};
        for(int j=0;j<7;j++){
            cout<<"\n是否修改"<<inform[j]<<"?(Y/N)";
            char judge;
            cin>>judge;
            switch(judge){
                case 'Y':
                case 'y':
                         if(inform[j]=="姓名"){
                                cout<<"请修改姓名：";
                                string name;
                                cin>>name;
                                students[i].set_Name(name);
                         }else if(inform[j]=="学号"){
                            cout<<"请修改学号：";
                            string id;
                            cin>>id;
                            students[i].set_ID(id);
                         }else if(inform[j]=="性别"){
                            string sex;
                            cout<<"请修改性别：";
                            cin>>sex;
                            if(sex=="男"||sex=="女"){
                                students[i].set_Sex(sex);
                            }
                         }else if(inform[j]=="班级"){
                            string cla;
                            cout<<"请修改班级：";
                            string a[0]="1";
                            cin>>cla;
                            while(cla!=a[0]){
                                cout<<"输入错误，请重新输入:";
                                cin>>cla;
                            }
                            students[i].set_Class(cla);
                         }else if(inform[j]=="英语"){
                             double english;
                             cout<<"请修改英语成绩：";
                             cin>>english;
                             if(english<0&&english>100){
                                cout<<"输入错误，请重新输入：";
                                cin>>english;
                             }
                             students[i].set_English(english);
                         }else if(inform[j]=="数学"){
                            double math;
                            cout<<"请修改数学成绩:";
                            cin>>math;
                            if(math<0&&math>100){
                                cout<<"输入错误，请重新输入：";
                                cin>>math;
                            }
                            students[i].set_Math(math);
                         }else{
                            double chinese;
                            cout<<"请修改语文成绩：";
                            cin>>chinese;
                            if(chinese<0&&chinese>100){
                                cout<<"输入错误，请重新输入：";
                                cin>>chinese;
                            }
                            students[i].set_Chinese(chinese);
                         }
            }   
        }
    }
    /*计算文件行数*/
    int CountLines(char *filename){
        ifstream ReadFile;
        int n=0;
        string tmp;
        ReadFile.open(filename,ios::in);
        if(ReadFile.fail()){
            return 0;
        }else{
            while(getline(ReadFile,tmp,'\n')){
                n++;
            }
            ReadFile.close();
            return n;
        }
    }
    public:
    /*将文件存到student_data.txt文件中*/
    void storageFunction(){
        ofstream outfile("student_data.txt",ios::out);
        for(int i=0;i<number;i++){
            outfile<<students[i].get_Name()<<" ";
            outfile<<students[i].get_ID()<<" ";
            outfile<<students[i].get_Sex()<<" ";
            outfile<<students[i].get_Class()<<" ";
            outfile<<students[i].get_English()<<" ";
            outfile<<students[i].get_Math()<<" ";
            outfile<<students[i].get_Chinese()<<" "<<endl;
        }
    }
    /*从student_data.txt文件中导入数据*/
    bool enterFunction(){
        ifstream infile("student_data.txt", ios::in);
        char filename[]="student_data.txt";
        int line=CountLines(filename);
    	for(int i = 0; i < line; i++)
    	{
    		string a[7];
    		for(int i = 0; i < 7; i++)
    		{
    			infile>>a[i];
    			//cout << a[i] << endl;
			}
			string name=a[0];
            string id=a[1];
            string sex=a[2];
            string cla=a[3];
            double english=stod(a[4]);
            double math=stod(a[5]);
            double chinese=stod(a[6]);
            Student student = Student(name,id,sex,cla,english,math,chinese);
            students[number++]=student;
		}
        
        return true;
    }
    /*增加学生信息*/
    bool addFunction(string name,string id,string sex,string cla,double english,double math,double chinese){
        string suffix="1";
        for(int i=0;i<number;i++){
            if(name==students[i].get_Name()){
                name=name+suffix;
            }
        }
        Student student=Student(name,id,sex,cla,english,math,chinese);
        if(number<1000){
            students[number++]=student;
            return true;
        }else{
            return false;
        }
    }
    /*展示学生信息*/
    bool showFunction(){
        cout<<"\n------------------------学生信息显示功能------------------------"<<endl;
        cout<<"姓名 \t学号 \t性别 \t班级 \t英语 \t数学 \t语文 \t排名 \t总分"<<endl;
        for(int i=0;i<number;i++){
            cout<<students[i].get_Name()<<"\t";
            cout<<students[i].get_ID()<<"\t";
            cout<<students[i].get_Sex()<<"\t";
            cout<<students[i].get_Class()<<"\t";
            cout<<students[i].get_English()<<"\t";
            cout<<students[i].get_Math()<<"\t";
            cout<<students[i].get_Chinese()<<"\t";
            cout<<students[i].get_Row()<<"\t";
            cout<<students[i].get_Sum()<<"\t"<<endl;
        }
        cout<<"------------------------------------------------------------------"<<endl;
        return true;
    }
    /*按姓名查找*/
    bool namefindFunction(string name){
        bool flag=false;
        for(int i=0;i<number;i++){
            if(name==students[i].get_Name()){
                flag=true;
                cout<<"学生"<<name<<"信息已找到，信息如下："<<endl;
                cout<<"\n"<<"名字 \t学号 \t性别 \t班级 \t英语 \t数学 \t语文 \t总分 \t平均分"<<endl;
                cout<<students[i].get_Name()<<"\t";
                cout<<students[i].get_ID()<<"\t";
                cout<<students[i].get_Sex()<<"\t";
                cout<<students[i].get_Class()<<"\t";
                cout<<students[i].get_English()<<"\t";
                cout<<students[i].get_Math()<<"\t";
                cout<<students[i].get_Chinese()<<"\t";
                cout<<students[i].get_Sum()<<"\t";
                cout<<students[i].get_Average()<<"\t";
            }
        }
        return flag;
    }
    /*按学号查找*/
    bool idfindFunction(string id){
        bool flag=false;
        for(int i=0;i<number;i++){
            if(id == students[i].get_ID()){
                flag=true;
                cout<<"学生"<<id<<"信息已找到，信息如下："<<endl;
                cout<<"\n"<<"名字 \t学号 \t性别 \t班级 \t英语 \t数学 \t语文 \t总分 \t平均分"<<endl;
                cout<<students[i].get_Name()<<"\t";
                cout<<students[i].get_ID()<<"\t";
                cout<<students[i].get_Sex()<<"\t";
                cout<<students[i].get_Class()<<"\t";
                cout<<students[i].get_English()<<"\t";
                cout<<students[i].get_Math()<<"\t";
                cout<<students[i].get_Chinese()<<"\t";
                cout<<students[i].get_Sum()<<"\t";
                cout<<students[i].get_Average()<<"\t";
            }
        }
        return flag;
    }
    /*按总分排序*/
    bool sumSortFunction(){
        for(int i=0;i<number;i++){
            for(int j=0;j<number-i-1;j++){
                if(students[j+1].get_Sum()>students[j].get_Sum()){
                    Student temp=students[j];
                    students[j]=students[j+1];
                    students[j+1]=temp;
                }
            }
        }
        for(int i=0;i<number;i++){
            students[i].set_Row(i+1);
        }
        for(int i=0;i<number;i++){
        	cout<<students[i].get_Name()<<" "<<students[i].get_Row();
		}
        return true;
    }
    /*名字查找并删除*/
    bool idDeleteFunction(string id){
        int num=0;
        bool flag = true;
        for(int i=0;i<number;i++){
            if(id==students[i].get_ID()){
                cout<<"学生"<<id<<"信息已找到,信息如下："<<endl;
                cout<<"\n"<<"名字 \t学号 \t性别 \t班级 \t英语 \t数学 \t语文 \t总分 \t平均分"<<endl;
                cout<<students[i].get_Name()<<"\t";
                cout<<students[i].get_ID()<<"\t";
                cout<<students[i].get_Sex()<<"\t";
                cout<<students[i].get_Class()<<"\t";
                cout<<students[i].get_English()<<"\t";
                cout<<students[i].get_Math()<<"\t";
                cout<<students[i].get_Chinese()<<"\t";
                cout<<students[i].get_Sum()<<"\t";
                cout<<students[i].get_Average()<<"\t"<<endl;
                num++;
                cout<<"\n是否确认删除学生"<<id<<"?(Y,N):";
                flag=_delete(i);
            }
        }
        if(flag){
            switch(num){
                case 0:
                       cout<<"未找到学生"<<id<<endl;
                       return false;
                default:
                        return true;
            }
        }
        return false;
    }
    /*学号查找并删除*/
    bool nameDeleteFunction(string name){
        int num=0;
        bool flag=true;
        for(int i=0;i<number;i++){
            if(name==students[i].get_Name()){
                cout<<"学生"<<name<<"信息已找到；信息如下："<<endl;
                cout<<"\n"<<"名字 \t学号 \t性别 \t班级 \t英语 \t数学 \t语文 \t总分 \t平均分"<<endl;
                cout<<students[i].get_Name()<<"\t";
                cout<<students[i].get_ID()<<"\t";
                cout<<students[i].get_Sex()<<"\t";
                cout<<students[i].get_Class()<<"\t";
                cout<<students[i].get_English()<<"\t";
                cout<<students[i].get_Math()<<"\t";
                cout<<students[i].get_Chinese()<<"\t";
                cout<<students[i].get_Sum()<<"\t";
                cout<<students[i].get_Average()<<"\t"<<endl;
                num++;
                cout<<"\n是否确认删除学生"<<name<<"?(Y/N):";
                flag=_delete(i);
            }
        }
        if(flag){
            switch(num){
                case 0:
                       cout<<"未找到学生"<<name<<",";
                       return false;
                default:
                        return true;
            }
        }
        return false;
    }
    /*通过学号修改*/
    bool idmodifyFunction(string id){
      int num=0;
      for(int i=0;i<number;i++){
        if(id==students[i].get_ID()){
            cout<<"学生"<<id<<"信息已找到；信息如下："<<endl;
                cout<<"\n"<<"名字 \t学号 \t性别 \t班级 \t英语 \t数学 \t语文 \t总分 \t平均分"<<endl;
                cout<<students[i].get_Name()<<"\t";
                cout<<students[i].get_ID()<<"\t";
                cout<<students[i].get_Sex()<<"\t";
                cout<<students[i].get_Class()<<"\t";
                cout<<students[i].get_English()<<"\t";
                cout<<students[i].get_Math()<<"\t";
                cout<<students[i].get_Chinese()<<"\t";
                cout<<students[i].get_Sum()<<"\t";
                cout<<students[i].get_Average()<<"\t"<<endl;
                num++;
                modify(i);
        }
      }
      switch(num){
        case 0:
                cout<<"未找到学生"<<id<<",";
                return false;
        default:
                return true;
      }  
    }
    /*通过姓名修改学生信息*/
    bool namemodifyFunction(string name){
        int num=0;
        for(int i=0;i<number;i++){
            if(name==students[i].get_Name()){
                cout<<"学生"<<name<<"信息已找到；信息如下："<<endl;
                cout<<"\n"<<"名字 \t学号 \t性别 \t班级 \t英语 \t数学 \t语文 \t总分 \t平均分"<<endl;
                cout<<students[i].get_Name()<<"\t";
                cout<<students[i].get_ID()<<"\t";
                cout<<students[i].get_Sex()<<"\t";
                cout<<students[i].get_Class()<<"\t";
                cout<<students[i].get_English()<<"\t";
                cout<<students[i].get_Math()<<"\t";
                cout<<students[i].get_Chinese()<<"\t";
                cout<<students[i].get_Sum()<<"\t";
                cout<<students[i].get_Average()<<"\t"<<endl;
                num++;
                modify(i);
            }
        }
        switch (num){
            case 0:
                    cout<<"未找到该学生"<<name<<",";
                    return false;
            default:
                    return true;
        }
    }
    /*英语平均分*/
    bool english_averageFunction(){
        bool flag=true;
        double english_average=0;
        for(int i=0;i<number;i++){
            english_average+=students[i].get_English();
        }
        english_average=english_average/number;
        cout<<"英语平均分为："<<english_average<<endl;
        return true;
    }
    /*数学平均分*/
    bool math_averageFunction(){
        bool flag=true;
        double math_average=0;
        for(int i=0;i<number;i++){
            math_average+=students[i].get_Math();
        }
        math_average=math_average/number;
        cout<<"数学平均分为："<<math_average<<endl;
        return true;
    }
    /*语文平均分*/
    bool chinese_averageFunction(){
        bool flag=true;
        double chinese_average=0;
        for(int i=0;i<number;i++){
            chinese_average+=students[i].get_Chinese();
        }
        chinese_average=chinese_average/number;
        cout<<"语文平均分为："<<chinese_average<<endl;
        return true;
    }
    /*英语及格率*/
    bool english_pass_rateFunction(){
        bool flag=true;
        double count=0;
        double english_pass_rate=0;
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=60){
                count++;
            }
        }
        english_pass_rate=count/double(number);
        cout<<"英语及格率为："<<english_pass_rate<<endl;
        return true;
    }
    /*数学及格率*/
    bool math_pass_rateFunction(){
        bool flag=true;
        double count=0;
        double math_pass_rate=0;
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=60){
                count++;
            }
        }
        math_pass_rate=count/double(number);
        cout<<"数学及格率为："<<math_pass_rate<<endl;
        return true;
    }
    /*语文及格率*/
    bool chinese_pass_rateFunction(){
        bool flag=true;
        double count=0;
        double chinese_pass_rate=0;
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=60){
                count++;
            }
        }
        chinese_pass_rate=count/double(number);
        cout<<"语文及格率为："<<chinese_pass_rate<<endl;
        return true;
    }
    /*英语柱状图*/
    bool english_histogramFunction(){
        int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
        cout<<"英语成绩统计如下"<<endl;

        cout<<"0~9"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=0&&students[i].get_English()<=9){
                cout<<"■";
                count1++;
            }
        }
        cout<<double(count1/double(number))*100<<"%"<<endl;

        cout<<"10~19"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=10&&students[i].get_English()<=19){
                cout<<"■";
                count2++;
            }
        }
        cout<<double(count2/double(number))*100<<"%"<<endl;

        cout<<"20~29"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=20&&students[i].get_English()<=29){
                cout<<"■";
                count3++;
            }
        }
        cout<<double(count3/double(number))*100<<"%"<<endl;

        cout<<"30~39"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=30&&students[i].get_English()<=39){
                cout<<"■";
                count4++;
            }
        }
        cout<<double(count4/double(number))*100<<"%"<<endl;

        cout<<"40~49"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=40&&students[i].get_English()<=49){
                cout<<"■";
                count5++;
            }
        }
        cout<<double(count5/double(number))*100<<"%"<<endl;

        cout<<"50~59"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=50&&students[i].get_English()<=59){
                cout<<"■";
                count6++;
            }
        }
        cout<<double(count6/double(number))*100<<"%"<<endl;

        cout<<"60~69"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=60&&students[i].get_English()<=69){
                cout<<"■";
                count7++;
            }
        }
        cout<<double(count7/double(number))*100<<"%"<<endl;

        cout<<"70~79"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=70&&students[i].get_English()<=79){
                cout<<"■";
                count8++;
            }
        }
        cout<<double(count8/double(number))*100<<"%"<<endl;

        cout<<"80~89"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=80&&students[i].get_English()<=89){
                cout<<"■";
                count9++;
            }
        }
        cout<<double(count9/double(number))*100<<"%"<<endl;

        cout<<"90~100"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=90&&students[i].get_English()<=100){
                cout<<"■";
                count10++;
            }
        }
        cout<<double(count10/double(number))*100<<"%"<<endl;
        return true;
    }
    /*数学柱状图*/
    bool math_histogramFunction(){
        int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
        cout<<"数学成绩统计如下"<<endl;

        cout<<"0~9"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=0&&students[i].get_Math()<=9){
                cout<<"■";
                count1++;
            }
        }
        cout<<double(count1/double(number))*100<<"%"<<endl;

        cout<<"10~19"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=10&&students[i].get_Math()<=19){
                cout<<"■";
                count2++;
            }
        }
        cout<<double(count2/double(number))*100<<"%"<<endl;

        cout<<"20~29"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=20&&students[i].get_Math()<=29){
                cout<<"■";
                count3++;
            }
        }
        cout<<double(count3/double(number))*100<<"%"<<endl;

        cout<<"30~39"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=30&&students[i].get_Math()<=39){
                cout<<"■";
                count4++;
            }
        }
        cout<<double(count4/double(number))*100<<"%"<<endl;

        cout<<"40~49"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=40&&students[i].get_Math()<=49){
                cout<<"■";
                count5++;
            }
        }
        cout<<double(count5/double(number))*100<<"%"<<endl;

        cout<<"50~59"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=50&&students[i].get_Math()<=59){
                cout<<"■";
                count6++;
            }
        }
        cout<<double(count6/double(number))*100<<"%"<<endl;

        cout<<"60~69"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=60&&students[i].get_Math()<=69){
                cout<<"■";
                count7++;
            }
        }
        cout<<double(count7/double(number))*100<<"%"<<endl;

        cout<<"70~79"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=70&&students[i].get_Math()<=79){
                cout<<"■";
                count8++;
            }
        }
        cout<<double(count8/double(number))*100<<"%"<<endl;

        cout<<"80~89"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=80&&students[i].get_Math()<=89){
                cout<<"■";
                count9++;
            }
        }
        cout<<double(count9/double(number))*100<<"%"<<endl;

        cout<<"90~100"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=90&&students[i].get_Math()<=100){
                cout<<"■";
                count10++;
            }
        }
        cout<<double(count10/double(number))*100<<"%"<<endl;
        return true;
    }
    /*语文柱状图*/
    bool chinese_histogramFunction(){
        int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
        cout<<"语文成绩统计如下"<<endl;

        cout<<"0~9"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=0&&students[i].get_Chinese()<=9){
                cout<<"■";
                count1++;
            }
        }
        cout<<double(count1/double(number))*100<<"%"<<endl;

        cout<<"10~19"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=10&&students[i].get_Chinese()<=19){
                cout<<"■";
                count2++;
            }
        }
        cout<<double(count2/double(number))*100<<"%"<<endl;

        cout<<"20~29"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=20&&students[i].get_Chinese()<=29){
                cout<<"■";
                count3++;
            }
        }
        cout<<double(count3/double(number))*100<<"%"<<endl;

        cout<<"30~39"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=30&&students[i].get_Chinese()<=39){
                cout<<"■";
                count4++;
            }
        }
        cout<<double(count4/double(number))*100<<"%"<<endl;

        cout<<"40~49"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=40&&students[i].get_Chinese()<=49){
                cout<<"■";
                count5++;
            }
        }
        cout<<double(count5/double(number))*100<<"%"<<endl;

        cout<<"50~59"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=50&&students[i].get_Chinese()<=59){
                cout<<"■";
                count6++;
            }
        }
        cout<<double(count6/double(number))*100<<"%"<<endl;

        cout<<"60~69"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=60&&students[i].get_Chinese()<=69){
                cout<<"■";
                count7++;
            }
        }
        cout<<double(count7/double(number))*100<<"%"<<endl;

        cout<<"70~79"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=70&&students[i].get_Chinese()<=79){
                cout<<"■";
                count8++;
            }
        }
        cout<<double(count8/double(number))*100<<"%"<<endl;

        cout<<"80~89"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=80&&students[i].get_Chinese()<=89){
                cout<<"■";
                count9++;
            }
        }
        cout<<double(count9/double(number))*100<<"%"<<endl;

        cout<<"90~100"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=90&&students[i].get_Chinese()<=100){
                cout<<"■";
                count10++;
            }
        }
        cout<<double(count10/double(number))*100<<"%"<<endl;
        return true;
    }
    
};
/*将系统功能导入系统*/
class System:public SystemFunction{
    private:
    SystemFunction systemFunction;
    bool compare(string old){
        string _new;
        try{
            int temp=stoi(old);
            _new=to_string(temp);
            if(old==_new){
                return true;
            }
            return false;
        }catch(...){
            return false;
        }
    }
    public:
    void main_menu(){
        bool flag = true;
        while(flag){
            cout << "\n-----------------学生信息管理系统-----------------" << endl;
            cout << "\t\t1.学生系统。"<<endl;
            cout << "\t\t2.管理员系统。"<<endl;
            cout << "\t\t3.退出程序。"<<endl;
            cout << "-----------------------------------------------" << endl;
            cout<<"请输入1~3"<<endl;
            int num_1;
            cin>>num_1;
            while(num_1>3||num_1<1){
                cout<<"输入错误，请重新输入"<<endl;
                cin>>num_1;
            }
            switch(num_1){
                case 1:
                        student_menu();
                        
                        cout<<"请输入1~2"<<endl;
                        int num_2;
                        cin>>num_2;
                        while(num_2>2||num_2<1){
                            cout<<"输入错误，请重新输入"<<endl;
                            cin>>num_2;
                        }
                        switch(num_2){
                            case 1:
                                    findStudent();
                                    system("pause");
                                    break;
                            case 2:
                                    cout<<"确认退出？（Y/N）：";
                                    char judge;
                                    cin>>judge;
                                    if(judge=='Y'||judge=='y'){
                                        systemFunction.storageFunction();
                                        flag=false;
                                        break;
                                    }
                                    system("pause");
                                    break;       
                        }
                        system("pause");
                        break;
                case 2:
                        manager_menu();
                        cout<<"请输入1~11"<<endl;
                        int num_3;
                        cin >> num_3;
                        while(num_3>11||num_3<1){
                            cout<<"输入错误，请重新输入"<<endl;
                            cin>>num_3;
                        }
                        switch(num_3){
                            case 1:
                                    enterStudent();
                                    system("pause");
                                    break;
                            case 2:
                                    addStudent();
                                    system("pause");
                                    break;
                            case 3:
                                    showStudent();
                                    system("pause");
                                    break;
                            case 4:
                                    findStudent();
                                    system("pause");
                                    break;
                            case 5:
                                    sumsortStudent();
                                    system("pause");
                                    break;
                            case 6:
                                    deleteStudent();
                                    system("pause");
                                    break;
                            case 7:
                                    modifyStudent();
                                    system("pause");
                                    break;
                            case 8:
                                    averageStudent();
                                    system("pause");
                                    break;
                            case 9:
                                    passrateStudent();
                                    system("pause");
                                    break;
                            case 10:
                                    histogramStudent();
                                    system("pause");
                                    break;
                            case 11:  
                                    cout<<"确认退出？（Y/N）：";
                                    char judge;
                                    cin>>judge;
                                    if(judge=='Y'||judge=='y'){
                                        systemFunction.storageFunction();
                                        flag=false;
                                        break;
                                    }
                                    system("pause");
                                    break;               
                        }
                        system("pause");
                        break;
                case 3:
                        cout<<"确认退出？（Y/N）：";
                                    char judge;
                                    cin>>judge;
                                    if(judge=='Y'||judge=='y'){
                                        systemFunction.storageFunction();
                                        flag=false;
                                        break;
                                    }
                                    system("pause");
                                    break; 
						system("pause");
						break;      
            }
        }
    }
    /*学生信息录入*/
        void enterStudent(){
            bool flag = systemFunction.enterFunction();
            if(flag){
                cout<<"学生信息录入成功！"<<endl;
            }else{
                cout<<"学生信息录入失败！"<<endl;
            }

        }
        /*新增学生信息*/
        void addStudent(){
            bool _flag=true;
            cout<<"\n-----------------新增学生信息-----------------" <<endl;
            cout<<"请输入新增学生姓名："<<endl;
            string a;
            cin>>a;
            cout<<"请输入新增学生学号：";
            string b;
            cin>>b;
            cout<<"请输入新增学生性别：";
            string c;
            cin>>c;
            cout<<"请输入新增学生班级：";
            string d;
            cin>>d;
            cout<<"请输入新增学生英语成绩：";
            double e;
            cin>>e;
            cout<<"请输入新增学生数学成绩：";
            double f;
            cin>>f;
            cout<<"请输入新增学生语文成绩：";
            double g;
            cin>>g;
            cout << "--------------------------------------------" << endl;
            bool flag = systemFunction.addFunction(a,b,c,d,e,f,g);
            if(flag){
                cout<<"新增学生成功！"<<endl;
            }else{
                cout<<"录入失败！"<<endl;
            }
        }
        /*学生信息展示*/
        void showStudent(){
            bool flag=systemFunction.showFunction();
            if(flag){
                cout<<"学生信息展示成功！"<<endl;
            }
        }
        /*学生信息查询*/
        void findStudent(){
            cout << "\n-----------------学生信息查询-----------------" << endl;
            string var;
            cout<<"请输入学生姓名或学号：";
            cin>>var;
            bool _flag = systemFunction.idfindFunction(var);
            bool flag = systemFunction.namefindFunction(var);
            if(flag||_flag){
                cout<<"找到学生"<<var<<"!"<<endl;
            }else{
                cout<<"未找到学生！"<<endl;
            }
            cout << "--------------------------------------------" << endl;
        }
        /*学生成绩排序*/
        void sumsortStudent(){
            bool flag=systemFunction.sumSortFunction();
            if(flag){
                cout<<"排序成功"<<endl;
                
            }
        }
        /*学生信息删除*/
        void deleteStudent(){
            cout << "\n-----------------学生信息删除-----------------" << endl;
            string var;
            cout<<"请输入待删除的学生的姓名或学号:";
            cin>>var;
            cout << "--------------------------------------------" << endl;
            bool _flag=systemFunction.idDeleteFunction(var);
            bool flag=systemFunction.nameDeleteFunction(var);
            if(flag||_flag){
                cout<<"学生"<<var<<"信息删除成功！"<<endl;
            }else{
                cout<<"信息删除失败！"<<endl;
            }
        }
        /*学生信息修改*/
        void modifyStudent(){
            cout << "\n-----------------学生信息修改-----------------" << endl;
            string var;
            cout<<"请输入待修改的学生的姓名或学号：";
            cin>>var;
            bool _flag=systemFunction.idmodifyFunction(var);
            bool flag =systemFunction.namemodifyFunction(var);
            if(flag||_flag){
                cout<<"修改学生"<<var<<"信息成功！"<<endl;
            }else{
                cout<<"修改学生信息失败！"<<endl;
            }
            cout << "--------------------------------------------" << endl;
        }
        /*科目平均分*/
        void averageStudent(){
            bool flag1=systemFunction.english_averageFunction();
            if(flag1){
                cout<<"英语平均分如上"<<endl;
            }
            bool flag2=systemFunction.math_averageFunction();
            if(flag2){
                cout<<"数学平均分如上"<<endl;
            }
            bool flag3=systemFunction.chinese_averageFunction();
            if(flag3){
                cout<<"语文平均分如上"<<endl;
            }
        }
        /*科目及格率*/
        void passrateStudent(){
            bool flag1=systemFunction.english_pass_rateFunction();
            if(flag1){
                cout<<"英语及格率如上"<<endl;
            }
            bool flag2=systemFunction.math_pass_rateFunction();
            if(flag2){
                cout<<"数学及格率如上"<<endl;
            }
            bool flag3=systemFunction.chinese_pass_rateFunction();
            if(flag3){
                cout<<"语文及格率如上"<<endl;
            }
        }
        void histogramStudent(){
            bool flag1=systemFunction.english_histogramFunction();
            bool flag2=systemFunction.math_histogramFunction();
            bool flag3=systemFunction.chinese_histogramFunction();
            if(flag1&&flag2&&flag3){
                cout<<"柱状图如让"<<endl;
            }
        }
    /*学生菜单*/
    void student_menu(){
        bool flag = true;
        if(flag){
            cout << "\n-----------------学生信息管理系统-----------------" << endl;
            cout <<"\t\t1.查询个人信息（学号/姓名）。"<<endl;
            cout <<"\t\t2.退出程序。"<<endl;
            cout << "-----------------------------------------------" << endl;
        }
    }
    /*管理员菜单*/
    void manager_menu(){
        bool flag = true;
        if(flag){
            cout << "\n-----------------学生信息管理系统-----------------" << endl;
            cout << "\t\t1.学生信息录入。" << endl;
            cout << "\t\t2.新增学生信息。" << endl;
            cout << "\t\t3.学生信息显示。" << endl;
            cout << "\t\t4.学生信息查询。" << endl;
            cout << "\t\t5.学生成绩排序。" << endl;
            cout << "\t\t6.学生信息删除。" << endl;
            cout << "\t\t7.学生信息修改。" << endl;
            cout << "\t\t8.科目平均成绩。" << endl;
            cout << "\t\t9.科目及格率。" << endl;
            cout << "\t\t10.成绩分布柱状图。"<<endl;
            cout << "\t\t11.退出程序。" << endl;
            cout << "-----------------------------------------------" << endl; 
        }
    }
};
int main(){
    System system;
    system.main_menu();
    return 0;
}
