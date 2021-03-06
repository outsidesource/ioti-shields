// DO NOT EDIT THIS FILE - it is machine generated
#ifndef SPL_JNIFunctions_com_ibm_iot4i_wally_examples_h
#define SPL_JNIFunctions_com_ibm_iot4i_wally_examples_h

#include <SPL/Runtime/Function/SPLJavaFunction.h>
#include <SPL/Runtime/Type/SPLType.h>

namespace SPL {
namespace JNIFunctions {
namespace com {
namespace ibm {
namespace iot4i {
namespace wally {
namespace examples {
class SPL_JNIFunctions {
public:

// Generated from com.ibm.iot4i.wally.examples.CheckTemperatureImpl in impl/java/bin/com/ibm/iot4i/wally/examples/CheckTemperatureImpl$StreamsModel.class at Mon Aug 28 10:55:12 EDT 2017
static SPL::boolean checkTemperature(SPL::ustring const & arg1) {
    static __thread void *func;
    static __thread jclass classGlobalRef;
    static __thread jmethodID mid;
    if (func == NULL) {
        func = SPL::SPLJavaFunction::loadFunction("TemperatureShield", "1.0.0", SPLJAVAFUNCTION_ADL_FILENAME, "impl/java/bin", "com.ibm.iot4i.wally.examples.CheckTemperatureImpl", "checkWaterLeakage", "(Ljava/lang/String;)Z", "com.ibm.iot4i.wally.examples", "<string T> public boolean checkTemperature(T message)", &classGlobalRef, &mid);
    }
    JNIEnv* env = SPL::SPLJavaFunction::getJNIEnv(func);
    jstring obj1 = env->NewString((jchar *) arg1.getBuffer(), (jsize) arg1.length());
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCreateError(func);
    SPL::boolean result = env->CallStaticBooleanMethod(classGlobalRef, mid, obj1);
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCallError(func);
    env->DeleteLocalRef(obj1);
    return result;
}

// Generated from com.ibm.iot4i.wally.examples.CheckTemperatureImpl in impl/java/bin/com/ibm/iot4i/wally/examples/CheckTemperatureImpl$StreamsModel.class at Mon Aug 28 10:55:12 EDT 2017
static SPL::boolean checkTemperature(SPL::rstring const & arg1) {
    SPL::boolean result = checkTemperature(SPL::ustring::fromUTF8(arg1));
    return result;
}

// Generated from com.ibm.iot4i.wally.examples.CheckTemperatureImpl in impl/java/bin/com/ibm/iot4i/wally/examples/CheckTemperatureImpl$StreamsModel.class at Mon Aug 28 10:55:12 EDT 2017
template <SPL::int32 msize>
static SPL::boolean checkTemperature(SPL::bstring<msize> const & arg1) {
    SPL::boolean result = checkTemperature((SPL::rstring) arg1);
    return result;
}

// Generated from com.ibm.iot4i.wally.examples.EntryConditionImpl in impl/java/bin/com/ibm/iot4i/wally/examples/EntryConditionImpl$StreamsModel.class at Mon Aug 28 10:55:12 EDT 2017
static SPL::boolean entryCondition(SPL::ustring const & arg1) {
    static __thread void *func;
    static __thread jclass classGlobalRef;
    static __thread jmethodID mid;
    if (func == NULL) {
        func = SPL::SPLJavaFunction::loadFunction("TemperatureShield", "1.0.0", SPLJAVAFUNCTION_ADL_FILENAME, "impl/java/bin", "com.ibm.iot4i.wally.examples.EntryConditionImpl", "entryCondition", "(Ljava/lang/String;)Z", "com.ibm.iot4i.wally.examples", "<string T> public boolean entryCondition(T message)", &classGlobalRef, &mid);
    }
    JNIEnv* env = SPL::SPLJavaFunction::getJNIEnv(func);
    jstring obj1 = env->NewString((jchar *) arg1.getBuffer(), (jsize) arg1.length());
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCreateError(func);
    SPL::boolean result = env->CallStaticBooleanMethod(classGlobalRef, mid, obj1);
    if (env->ExceptionCheck())
        SPL::SPLJavaFunction::throwCallError(func);
    env->DeleteLocalRef(obj1);
    return result;
}

// Generated from com.ibm.iot4i.wally.examples.EntryConditionImpl in impl/java/bin/com/ibm/iot4i/wally/examples/EntryConditionImpl$StreamsModel.class at Mon Aug 28 10:55:12 EDT 2017
static SPL::boolean entryCondition(SPL::rstring const & arg1) {
    SPL::boolean result = entryCondition(SPL::ustring::fromUTF8(arg1));
    return result;
}

// Generated from com.ibm.iot4i.wally.examples.EntryConditionImpl in impl/java/bin/com/ibm/iot4i/wally/examples/EntryConditionImpl$StreamsModel.class at Mon Aug 28 10:55:12 EDT 2017
template <SPL::int32 msize>
static SPL::boolean entryCondition(SPL::bstring<msize> const & arg1) {
    SPL::boolean result = entryCondition((SPL::rstring) arg1);
    return result;
}

};
}
}
}
}
}
}
}
#endif
