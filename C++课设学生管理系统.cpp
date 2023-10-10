#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;
#define Max 50;/*�������*/
/*ѧ���࣬���ڷ�����Ϣ����������*/
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
/*ϵͳ������*/
class SystemFunction:public Student{
    private:
    Student students[1000];/*ѧ��������*/
    string studentId;
    int number=0;
    /*ɾ������*/
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
            cout<<"��������ɾ��ʧ��";
            return false;
        }
    }
    /*�޸Ĺ���*/
    void modify(int i){
        string inform[]={"����","ѧ��","�Ա�","�༶","Ӣ��","��ѧ","����"};
        for(int j=0;j<7;j++){
            cout<<"\n�Ƿ��޸�"<<inform[j]<<"?(Y/N)";
            char judge;
            cin>>judge;
            switch(judge){
                case 'Y':
                case 'y':
                         if(inform[j]=="����"){
                                cout<<"���޸�������";
                                string name;
                                cin>>name;
                                students[i].set_Name(name);
                         }else if(inform[j]=="ѧ��"){
                            cout<<"���޸�ѧ�ţ�";
                            string id;
                            cin>>id;
                            students[i].set_ID(id);
                         }else if(inform[j]=="�Ա�"){
                            string sex;
                            cout<<"���޸��Ա�";
                            cin>>sex;
                            if(sex=="��"||sex=="Ů"){
                                students[i].set_Sex(sex);
                            }
                         }else if(inform[j]=="�༶"){
                            string cla;
                            cout<<"���޸İ༶��";
                            string a[0]="1";
                            cin>>cla;
                            while(cla!=a[0]){
                                cout<<"�����������������:";
                                cin>>cla;
                            }
                            students[i].set_Class(cla);
                         }else if(inform[j]=="Ӣ��"){
                             double english;
                             cout<<"���޸�Ӣ��ɼ���";
                             cin>>english;
                             if(english<0&&english>100){
                                cout<<"����������������룺";
                                cin>>english;
                             }
                             students[i].set_English(english);
                         }else if(inform[j]=="��ѧ"){
                            double math;
                            cout<<"���޸���ѧ�ɼ�:";
                            cin>>math;
                            if(math<0&&math>100){
                                cout<<"����������������룺";
                                cin>>math;
                            }
                            students[i].set_Math(math);
                         }else{
                            double chinese;
                            cout<<"���޸����ĳɼ���";
                            cin>>chinese;
                            if(chinese<0&&chinese>100){
                                cout<<"����������������룺";
                                cin>>chinese;
                            }
                            students[i].set_Chinese(chinese);
                         }
            }   
        }
    }
    /*�����ļ�����*/
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
    /*���ļ��浽student_data.txt�ļ���*/
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
    /*��student_data.txt�ļ��е�������*/
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
    /*����ѧ����Ϣ*/
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
    /*չʾѧ����Ϣ*/
    bool showFunction(){
        cout<<"\n------------------------ѧ����Ϣ��ʾ����------------------------"<<endl;
        cout<<"���� \tѧ�� \t�Ա� \t�༶ \tӢ�� \t��ѧ \t���� \t���� \t�ܷ�"<<endl;
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
    /*����������*/
    bool namefindFunction(string name){
        bool flag=false;
        for(int i=0;i<number;i++){
            if(name==students[i].get_Name()){
                flag=true;
                cout<<"ѧ��"<<name<<"��Ϣ���ҵ�����Ϣ���£�"<<endl;
                cout<<"\n"<<"���� \tѧ�� \t�Ա� \t�༶ \tӢ�� \t��ѧ \t���� \t�ܷ� \tƽ����"<<endl;
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
    /*��ѧ�Ų���*/
    bool idfindFunction(string id){
        bool flag=false;
        for(int i=0;i<number;i++){
            if(id == students[i].get_ID()){
                flag=true;
                cout<<"ѧ��"<<id<<"��Ϣ���ҵ�����Ϣ���£�"<<endl;
                cout<<"\n"<<"���� \tѧ�� \t�Ա� \t�༶ \tӢ�� \t��ѧ \t���� \t�ܷ� \tƽ����"<<endl;
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
    /*���ܷ�����*/
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
    /*���ֲ��Ҳ�ɾ��*/
    bool idDeleteFunction(string id){
        int num=0;
        bool flag = true;
        for(int i=0;i<number;i++){
            if(id==students[i].get_ID()){
                cout<<"ѧ��"<<id<<"��Ϣ���ҵ�,��Ϣ���£�"<<endl;
                cout<<"\n"<<"���� \tѧ�� \t�Ա� \t�༶ \tӢ�� \t��ѧ \t���� \t�ܷ� \tƽ����"<<endl;
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
                cout<<"\n�Ƿ�ȷ��ɾ��ѧ��"<<id<<"?(Y,N):";
                flag=_delete(i);
            }
        }
        if(flag){
            switch(num){
                case 0:
                       cout<<"δ�ҵ�ѧ��"<<id<<endl;
                       return false;
                default:
                        return true;
            }
        }
        return false;
    }
    /*ѧ�Ų��Ҳ�ɾ��*/
    bool nameDeleteFunction(string name){
        int num=0;
        bool flag=true;
        for(int i=0;i<number;i++){
            if(name==students[i].get_Name()){
                cout<<"ѧ��"<<name<<"��Ϣ���ҵ�����Ϣ���£�"<<endl;
                cout<<"\n"<<"���� \tѧ�� \t�Ա� \t�༶ \tӢ�� \t��ѧ \t���� \t�ܷ� \tƽ����"<<endl;
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
                cout<<"\n�Ƿ�ȷ��ɾ��ѧ��"<<name<<"?(Y/N):";
                flag=_delete(i);
            }
        }
        if(flag){
            switch(num){
                case 0:
                       cout<<"δ�ҵ�ѧ��"<<name<<",";
                       return false;
                default:
                        return true;
            }
        }
        return false;
    }
    /*ͨ��ѧ���޸�*/
    bool idmodifyFunction(string id){
      int num=0;
      for(int i=0;i<number;i++){
        if(id==students[i].get_ID()){
            cout<<"ѧ��"<<id<<"��Ϣ���ҵ�����Ϣ���£�"<<endl;
                cout<<"\n"<<"���� \tѧ�� \t�Ա� \t�༶ \tӢ�� \t��ѧ \t���� \t�ܷ� \tƽ����"<<endl;
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
                cout<<"δ�ҵ�ѧ��"<<id<<",";
                return false;
        default:
                return true;
      }  
    }
    /*ͨ�������޸�ѧ����Ϣ*/
    bool namemodifyFunction(string name){
        int num=0;
        for(int i=0;i<number;i++){
            if(name==students[i].get_Name()){
                cout<<"ѧ��"<<name<<"��Ϣ���ҵ�����Ϣ���£�"<<endl;
                cout<<"\n"<<"���� \tѧ�� \t�Ա� \t�༶ \tӢ�� \t��ѧ \t���� \t�ܷ� \tƽ����"<<endl;
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
                    cout<<"δ�ҵ���ѧ��"<<name<<",";
                    return false;
            default:
                    return true;
        }
    }
    /*Ӣ��ƽ����*/
    bool english_averageFunction(){
        bool flag=true;
        double english_average=0;
        for(int i=0;i<number;i++){
            english_average+=students[i].get_English();
        }
        english_average=english_average/number;
        cout<<"Ӣ��ƽ����Ϊ��"<<english_average<<endl;
        return true;
    }
    /*��ѧƽ����*/
    bool math_averageFunction(){
        bool flag=true;
        double math_average=0;
        for(int i=0;i<number;i++){
            math_average+=students[i].get_Math();
        }
        math_average=math_average/number;
        cout<<"��ѧƽ����Ϊ��"<<math_average<<endl;
        return true;
    }
    /*����ƽ����*/
    bool chinese_averageFunction(){
        bool flag=true;
        double chinese_average=0;
        for(int i=0;i<number;i++){
            chinese_average+=students[i].get_Chinese();
        }
        chinese_average=chinese_average/number;
        cout<<"����ƽ����Ϊ��"<<chinese_average<<endl;
        return true;
    }
    /*Ӣ�Ｐ����*/
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
        cout<<"Ӣ�Ｐ����Ϊ��"<<english_pass_rate<<endl;
        return true;
    }
    /*��ѧ������*/
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
        cout<<"��ѧ������Ϊ��"<<math_pass_rate<<endl;
        return true;
    }
    /*���ļ�����*/
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
        cout<<"���ļ�����Ϊ��"<<chinese_pass_rate<<endl;
        return true;
    }
    /*Ӣ����״ͼ*/
    bool english_histogramFunction(){
        int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
        cout<<"Ӣ��ɼ�ͳ������"<<endl;

        cout<<"0~9"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=0&&students[i].get_English()<=9){
                cout<<"��";
                count1++;
            }
        }
        cout<<double(count1/double(number))*100<<"%"<<endl;

        cout<<"10~19"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=10&&students[i].get_English()<=19){
                cout<<"��";
                count2++;
            }
        }
        cout<<double(count2/double(number))*100<<"%"<<endl;

        cout<<"20~29"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=20&&students[i].get_English()<=29){
                cout<<"��";
                count3++;
            }
        }
        cout<<double(count3/double(number))*100<<"%"<<endl;

        cout<<"30~39"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=30&&students[i].get_English()<=39){
                cout<<"��";
                count4++;
            }
        }
        cout<<double(count4/double(number))*100<<"%"<<endl;

        cout<<"40~49"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=40&&students[i].get_English()<=49){
                cout<<"��";
                count5++;
            }
        }
        cout<<double(count5/double(number))*100<<"%"<<endl;

        cout<<"50~59"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=50&&students[i].get_English()<=59){
                cout<<"��";
                count6++;
            }
        }
        cout<<double(count6/double(number))*100<<"%"<<endl;

        cout<<"60~69"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=60&&students[i].get_English()<=69){
                cout<<"��";
                count7++;
            }
        }
        cout<<double(count7/double(number))*100<<"%"<<endl;

        cout<<"70~79"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=70&&students[i].get_English()<=79){
                cout<<"��";
                count8++;
            }
        }
        cout<<double(count8/double(number))*100<<"%"<<endl;

        cout<<"80~89"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=80&&students[i].get_English()<=89){
                cout<<"��";
                count9++;
            }
        }
        cout<<double(count9/double(number))*100<<"%"<<endl;

        cout<<"90~100"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_English()>=90&&students[i].get_English()<=100){
                cout<<"��";
                count10++;
            }
        }
        cout<<double(count10/double(number))*100<<"%"<<endl;
        return true;
    }
    /*��ѧ��״ͼ*/
    bool math_histogramFunction(){
        int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
        cout<<"��ѧ�ɼ�ͳ������"<<endl;

        cout<<"0~9"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=0&&students[i].get_Math()<=9){
                cout<<"��";
                count1++;
            }
        }
        cout<<double(count1/double(number))*100<<"%"<<endl;

        cout<<"10~19"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=10&&students[i].get_Math()<=19){
                cout<<"��";
                count2++;
            }
        }
        cout<<double(count2/double(number))*100<<"%"<<endl;

        cout<<"20~29"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=20&&students[i].get_Math()<=29){
                cout<<"��";
                count3++;
            }
        }
        cout<<double(count3/double(number))*100<<"%"<<endl;

        cout<<"30~39"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=30&&students[i].get_Math()<=39){
                cout<<"��";
                count4++;
            }
        }
        cout<<double(count4/double(number))*100<<"%"<<endl;

        cout<<"40~49"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=40&&students[i].get_Math()<=49){
                cout<<"��";
                count5++;
            }
        }
        cout<<double(count5/double(number))*100<<"%"<<endl;

        cout<<"50~59"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=50&&students[i].get_Math()<=59){
                cout<<"��";
                count6++;
            }
        }
        cout<<double(count6/double(number))*100<<"%"<<endl;

        cout<<"60~69"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=60&&students[i].get_Math()<=69){
                cout<<"��";
                count7++;
            }
        }
        cout<<double(count7/double(number))*100<<"%"<<endl;

        cout<<"70~79"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=70&&students[i].get_Math()<=79){
                cout<<"��";
                count8++;
            }
        }
        cout<<double(count8/double(number))*100<<"%"<<endl;

        cout<<"80~89"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=80&&students[i].get_Math()<=89){
                cout<<"��";
                count9++;
            }
        }
        cout<<double(count9/double(number))*100<<"%"<<endl;

        cout<<"90~100"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Math()>=90&&students[i].get_Math()<=100){
                cout<<"��";
                count10++;
            }
        }
        cout<<double(count10/double(number))*100<<"%"<<endl;
        return true;
    }
    /*������״ͼ*/
    bool chinese_histogramFunction(){
        int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0;
        cout<<"���ĳɼ�ͳ������"<<endl;

        cout<<"0~9"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=0&&students[i].get_Chinese()<=9){
                cout<<"��";
                count1++;
            }
        }
        cout<<double(count1/double(number))*100<<"%"<<endl;

        cout<<"10~19"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=10&&students[i].get_Chinese()<=19){
                cout<<"��";
                count2++;
            }
        }
        cout<<double(count2/double(number))*100<<"%"<<endl;

        cout<<"20~29"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=20&&students[i].get_Chinese()<=29){
                cout<<"��";
                count3++;
            }
        }
        cout<<double(count3/double(number))*100<<"%"<<endl;

        cout<<"30~39"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=30&&students[i].get_Chinese()<=39){
                cout<<"��";
                count4++;
            }
        }
        cout<<double(count4/double(number))*100<<"%"<<endl;

        cout<<"40~49"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=40&&students[i].get_Chinese()<=49){
                cout<<"��";
                count5++;
            }
        }
        cout<<double(count5/double(number))*100<<"%"<<endl;

        cout<<"50~59"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=50&&students[i].get_Chinese()<=59){
                cout<<"��";
                count6++;
            }
        }
        cout<<double(count6/double(number))*100<<"%"<<endl;

        cout<<"60~69"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=60&&students[i].get_Chinese()<=69){
                cout<<"��";
                count7++;
            }
        }
        cout<<double(count7/double(number))*100<<"%"<<endl;

        cout<<"70~79"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=70&&students[i].get_Chinese()<=79){
                cout<<"��";
                count8++;
            }
        }
        cout<<double(count8/double(number))*100<<"%"<<endl;

        cout<<"80~89"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=80&&students[i].get_Chinese()<=89){
                cout<<"��";
                count9++;
            }
        }
        cout<<double(count9/double(number))*100<<"%"<<endl;

        cout<<"90~100"<<" ";
        for(int i=0;i<number;i++){
            if(students[i].get_Chinese()>=90&&students[i].get_Chinese()<=100){
                cout<<"��";
                count10++;
            }
        }
        cout<<double(count10/double(number))*100<<"%"<<endl;
        return true;
    }
    
};
/*��ϵͳ���ܵ���ϵͳ*/
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
            cout << "\n-----------------ѧ����Ϣ����ϵͳ-----------------" << endl;
            cout << "\t\t1.ѧ��ϵͳ��"<<endl;
            cout << "\t\t2.����Աϵͳ��"<<endl;
            cout << "\t\t3.�˳�����"<<endl;
            cout << "-----------------------------------------------" << endl;
            cout<<"������1~3"<<endl;
            int num_1;
            cin>>num_1;
            while(num_1>3||num_1<1){
                cout<<"�����������������"<<endl;
                cin>>num_1;
            }
            switch(num_1){
                case 1:
                        student_menu();
                        
                        cout<<"������1~2"<<endl;
                        int num_2;
                        cin>>num_2;
                        while(num_2>2||num_2<1){
                            cout<<"�����������������"<<endl;
                            cin>>num_2;
                        }
                        switch(num_2){
                            case 1:
                                    findStudent();
                                    system("pause");
                                    break;
                            case 2:
                                    cout<<"ȷ���˳�����Y/N����";
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
                        cout<<"������1~11"<<endl;
                        int num_3;
                        cin >> num_3;
                        while(num_3>11||num_3<1){
                            cout<<"�����������������"<<endl;
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
                                    cout<<"ȷ���˳�����Y/N����";
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
                        cout<<"ȷ���˳�����Y/N����";
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
    /*ѧ����Ϣ¼��*/
        void enterStudent(){
            bool flag = systemFunction.enterFunction();
            if(flag){
                cout<<"ѧ����Ϣ¼��ɹ���"<<endl;
            }else{
                cout<<"ѧ����Ϣ¼��ʧ�ܣ�"<<endl;
            }

        }
        /*����ѧ����Ϣ*/
        void addStudent(){
            bool _flag=true;
            cout<<"\n-----------------����ѧ����Ϣ-----------------" <<endl;
            cout<<"����������ѧ��������"<<endl;
            string a;
            cin>>a;
            cout<<"����������ѧ��ѧ�ţ�";
            string b;
            cin>>b;
            cout<<"����������ѧ���Ա�";
            string c;
            cin>>c;
            cout<<"����������ѧ���༶��";
            string d;
            cin>>d;
            cout<<"����������ѧ��Ӣ��ɼ���";
            double e;
            cin>>e;
            cout<<"����������ѧ����ѧ�ɼ���";
            double f;
            cin>>f;
            cout<<"����������ѧ�����ĳɼ���";
            double g;
            cin>>g;
            cout << "--------------------------------------------" << endl;
            bool flag = systemFunction.addFunction(a,b,c,d,e,f,g);
            if(flag){
                cout<<"����ѧ���ɹ���"<<endl;
            }else{
                cout<<"¼��ʧ�ܣ�"<<endl;
            }
        }
        /*ѧ����Ϣչʾ*/
        void showStudent(){
            bool flag=systemFunction.showFunction();
            if(flag){
                cout<<"ѧ����Ϣչʾ�ɹ���"<<endl;
            }
        }
        /*ѧ����Ϣ��ѯ*/
        void findStudent(){
            cout << "\n-----------------ѧ����Ϣ��ѯ-----------------" << endl;
            string var;
            cout<<"������ѧ��������ѧ�ţ�";
            cin>>var;
            bool _flag = systemFunction.idfindFunction(var);
            bool flag = systemFunction.namefindFunction(var);
            if(flag||_flag){
                cout<<"�ҵ�ѧ��"<<var<<"!"<<endl;
            }else{
                cout<<"δ�ҵ�ѧ����"<<endl;
            }
            cout << "--------------------------------------------" << endl;
        }
        /*ѧ���ɼ�����*/
        void sumsortStudent(){
            bool flag=systemFunction.sumSortFunction();
            if(flag){
                cout<<"����ɹ�"<<endl;
                
            }
        }
        /*ѧ����Ϣɾ��*/
        void deleteStudent(){
            cout << "\n-----------------ѧ����Ϣɾ��-----------------" << endl;
            string var;
            cout<<"�������ɾ����ѧ����������ѧ��:";
            cin>>var;
            cout << "--------------------------------------------" << endl;
            bool _flag=systemFunction.idDeleteFunction(var);
            bool flag=systemFunction.nameDeleteFunction(var);
            if(flag||_flag){
                cout<<"ѧ��"<<var<<"��Ϣɾ���ɹ���"<<endl;
            }else{
                cout<<"��Ϣɾ��ʧ�ܣ�"<<endl;
            }
        }
        /*ѧ����Ϣ�޸�*/
        void modifyStudent(){
            cout << "\n-----------------ѧ����Ϣ�޸�-----------------" << endl;
            string var;
            cout<<"��������޸ĵ�ѧ����������ѧ�ţ�";
            cin>>var;
            bool _flag=systemFunction.idmodifyFunction(var);
            bool flag =systemFunction.namemodifyFunction(var);
            if(flag||_flag){
                cout<<"�޸�ѧ��"<<var<<"��Ϣ�ɹ���"<<endl;
            }else{
                cout<<"�޸�ѧ����Ϣʧ�ܣ�"<<endl;
            }
            cout << "--------------------------------------------" << endl;
        }
        /*��Ŀƽ����*/
        void averageStudent(){
            bool flag1=systemFunction.english_averageFunction();
            if(flag1){
                cout<<"Ӣ��ƽ��������"<<endl;
            }
            bool flag2=systemFunction.math_averageFunction();
            if(flag2){
                cout<<"��ѧƽ��������"<<endl;
            }
            bool flag3=systemFunction.chinese_averageFunction();
            if(flag3){
                cout<<"����ƽ��������"<<endl;
            }
        }
        /*��Ŀ������*/
        void passrateStudent(){
            bool flag1=systemFunction.english_pass_rateFunction();
            if(flag1){
                cout<<"Ӣ�Ｐ��������"<<endl;
            }
            bool flag2=systemFunction.math_pass_rateFunction();
            if(flag2){
                cout<<"��ѧ����������"<<endl;
            }
            bool flag3=systemFunction.chinese_pass_rateFunction();
            if(flag3){
                cout<<"���ļ���������"<<endl;
            }
        }
        void histogramStudent(){
            bool flag1=systemFunction.english_histogramFunction();
            bool flag2=systemFunction.math_histogramFunction();
            bool flag3=systemFunction.chinese_histogramFunction();
            if(flag1&&flag2&&flag3){
                cout<<"��״ͼ����"<<endl;
            }
        }
    /*ѧ���˵�*/
    void student_menu(){
        bool flag = true;
        if(flag){
            cout << "\n-----------------ѧ����Ϣ����ϵͳ-----------------" << endl;
            cout <<"\t\t1.��ѯ������Ϣ��ѧ��/��������"<<endl;
            cout <<"\t\t2.�˳�����"<<endl;
            cout << "-----------------------------------------------" << endl;
        }
    }
    /*����Ա�˵�*/
    void manager_menu(){
        bool flag = true;
        if(flag){
            cout << "\n-----------------ѧ����Ϣ����ϵͳ-----------------" << endl;
            cout << "\t\t1.ѧ����Ϣ¼�롣" << endl;
            cout << "\t\t2.����ѧ����Ϣ��" << endl;
            cout << "\t\t3.ѧ����Ϣ��ʾ��" << endl;
            cout << "\t\t4.ѧ����Ϣ��ѯ��" << endl;
            cout << "\t\t5.ѧ���ɼ�����" << endl;
            cout << "\t\t6.ѧ����Ϣɾ����" << endl;
            cout << "\t\t7.ѧ����Ϣ�޸ġ�" << endl;
            cout << "\t\t8.��Ŀƽ���ɼ���" << endl;
            cout << "\t\t9.��Ŀ�����ʡ�" << endl;
            cout << "\t\t10.�ɼ��ֲ���״ͼ��"<<endl;
            cout << "\t\t11.�˳�����" << endl;
            cout << "-----------------------------------------------" << endl; 
        }
    }
};
int main(){
    System system;
    system.main_menu();
    return 0;
}
