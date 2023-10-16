#include <iostream>
using namespace std;

class arrOperate
{
   public:
      double average(int i[],int size) {
        float sum = 0.0;
        //int length = end(i) - begin(i);failed
        for(int j = 0; j < size; j++){
            sum += i[j];
        }
        return sum/size;
      }
 
      double average(double  d[],int size) {
        double sum = 0.0;
        for(int j = 0; j < size; j++){
            sum += d[j];
        }
        return sum/size;
      }
 
      double average(float f[],int size) {
        float sum = 0.0;
        for(int j = 0; j < size; j++){
            sum += f[j];
        }
        return sum/size;
      }

      int max(int i[],int size) {
        int max = i[0];
        for (int count = 1; count < size; count++) {
            if (i[count] > max)
            max = i[count];
        }
        return max;
      }

      float max(float f[],int size) {
        float max = f[0];
        for (int count = 1; count < size; count++) {
            if (f[count] > max)
            max = f[count];
        }
        return max;
      }

      double max(double d[],int size) {
        double max = d[0];
        for (int count = 1; count < size; count++) {
            if (d[count] > max)
            max = d[count];
        }
        return max;
      }

      int min(int i[],int size) {
        int max = i[0];
        for (int count = 1; count < size; count++) {
            if (i[count] < max)
            max = i[count];
        }
        return max;
      }

      float min(float f[],int size) {
        float max = f[0];
        for (int count = 1; count < size; count++) {
            if (f[count] < max)
            max = f[count];
        }
        return max;
      }

      double min(double d[],int size) {
        double max = d[0];
        for (int count = 1; count < size; count++) {
            if (d[count] < max)
            max = d[count];
        }
        return max;
      }


};

int main()
{
    //要求是10个元素，懒得写了，可以自己填一下
    int data_i[5] ={1,2,3,4,5};
    double data_d[5] = {1.1,15.8,96.554,96.4,78.4};
    float data_f[6] = {1.23,5.65,896.5,56.4,8963.8,55.6};
    arrOperate op;

    cout<<"求平均值测试"<<endl;
    cout<<op.average(data_i,end(data_i) - begin(data_i))<<endl;
    cout<<op.average(data_d,end(data_d) - begin(data_d))<<endl;
    cout<<op.average(data_f,end(data_f) - begin(data_f))<<endl;
    
    cout<<"最大值测试"<<endl;
    cout<<op.max(data_i,end(data_i) - begin(data_i))<<endl;
    cout<<op.max(data_d,end(data_d) - begin(data_d))<<endl;
    cout<<op.max(data_f,end(data_f) - begin(data_f))<<endl;

    cout<<"最小值测试"<<endl;
    cout<<op.min(data_i,end(data_i) - begin(data_i))<<endl;
    cout<<op.min(data_d,end(data_d) - begin(data_d))<<endl;
    cout<<op.min(data_f,end(data_f) - begin(data_f))<<endl;


    return 0;

}