#include "react-native-env-js.h"
#include <jsi/jsi.h>

using namespace facebook;
using namespace std;

void installSequel(jsi::Runtime &rt)
{
    auto getEnvironmentVariableLambda = [](jsi::Runtime &rt,
                                           const jsi::Value &thisValue,
                                           const jsi::Value *args,
                                           size_t count) -> jsi::Value
    {
        return jsi::Value(42);
    };

    jsi::Function getEnvironmentVariable = jsi::Function::createFromHostFunction(
        rt,
        jsi::PropNameID::forAscii(rt, "getEnvironmentVariable"),
        0,
        move(getEnvironmentVariableLambda));

    rt.global().setProperty(rt, "getEnvironmentVariable", move(getEnvironmentVariable));
}

void cleanUpSequel() {}
