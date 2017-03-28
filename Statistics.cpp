#include <jni.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Statistics.h"

using namespace std;

JNIEXPORT jdouble JNICALL Java_Statistics_sum 
(JNIEnv *env, jclass thisObj, jintArray inJNIArray) {
    jboolean is_copy;
    jint *inCArray = env->GetIntArrayElements(inJNIArray, &is_copy);
    if (inCArray == NULL){
        return 0.0;
    }

    jsize length = env->GetArrayLength(inJNIArray);
                            
    jint sum = 0;
    int i;
    for (i = 0; i < length; i++) {
        sum += inCArray[i];
    }
    env->ReleaseIntArrayElements(inJNIArray, inCArray, 0);
    return sum;
}

JNIEXPORT jdouble JNICALL Java_Statistics_avg
(JNIEnv *env, jclass thisObj, jintArray inJNIArray) {
    jsize length = env->GetArrayLength(inJNIArray);
    return Java_Statistics_sum (env, thisObj, inJNIArray)/((jdouble)(length));
}

JNIEXPORT jdouble JNICALL Java_Statistics_stddev
(JNIEnv *env, jclass thisObj, jintArray inJNIArray) {
    jsize length = env->GetArrayLength(inJNIArray);
    jboolean is_copy;
    jint *inCArray = env->GetIntArrayElements(inJNIArray, &is_copy);

    if (inCArray == NULL){
        return 0.0;
    }

    jdouble sum = 0;
    jdouble average = Java_Statistics_avg(env, thisObj, inJNIArray);
    for (int i = 0; i < length; i++) {
        jint value = inCArray[i];
        sum += pow(value - average,2);
    }
    return sqrt(sum/(jdouble)length);
}

