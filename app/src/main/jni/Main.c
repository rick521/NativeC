#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
/* Header for class date_hb_com_jninative_MainActivity */

#ifndef _Included_com_example_nativec_MainActivity
#define _Included_com_example_nativec_MainActivity
#ifdef __cplusplus

extern "C" {
#endif
double s_int;
void int_comp(void);//整点运算
JNIEXPORT jstring JNICALL Java_com_example_nativec_MainActivity_get
  (JNIEnv * env, jobject obj){
     char buf[64];
     int_comp();
     sprintf(buf, "%f",s_int);
     return (*env)->NewStringUTF(env,buf);
  }

JNIEXPORT void JNICALL Java_com_example_nativec_MainActivity_set
  (JNIEnv * env, jobject obj, jstring str){
    (*env)->NewStringUTF(env,"Hello JNI!");
  }



#include <time.h>//clock()所属头文件
const int N_qsort=10000;//快排的数据规模
const int M=20000,N=50000;//整点、浮点运算的规模
const int N_pi=100000000;//计算圆周率的运算规模






void int_comp(void){//整点加法
     clock_t start,end;
     int i,j;
     start=clock();
     for(i=0;i<M;i++)
         for(j=0;j<N;j++);
     end=clock();
     double duration=(double)(end-start)/CLOCKS_PER_SEC;
     double score=(M*N)/duration;

     /*注：score本身即为运算速度，数量级一般在亿，为方便起见，本程序的分数均采用运算速度除以一万后的结果！除特殊说明，后面类同！*/
     s_int=score/10000;
     //printf("整点运算测试完毕!分数:%lf\n",s_int);
}

#ifdef __cplusplus
}
#endif
#endif
