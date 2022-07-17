#include "react-native-env-js.h"
#include <jsi/jsi.h>
#include "java-bindings/JEnvJs.h"

using namespace facebook;
using namespace std;
using namespace envjs;

void installSequel(jsi::Runtime &rt)
{
    auto getEnvironmentVariableLambda = [](jsi::Runtime &rt,
                                           const jsi::Value &thisValue,
                                           const jsi::Value *args,
                                           size_t count) -> jsi::Value
    {
        if (count < 1) {
            jsi::detail::throwJSError(rt, "[react-native-env-js]: environment variable name is not defined.");
        }

        if (!args[0].isString()) {
            jsi::detail::throwJSError(rt, "[react-native-env-js]: environment variable name should be string.");
        }

        auto environmentVariableName = args[0].getString(rt);

        auto environmentVariable = JEnvJs::getEnvironmentVariable(environmentVariableName.utf8(rt));

        if (environmentVariable.empty()) {
            return nullptr;
        }

        return jsi::String::createFromUtf8(rt, environmentVariable);
    };

    jsi::Function getEnvironmentVariable = jsi::Function::createFromHostFunction(
        rt,
        jsi::PropNameID::forAscii(rt, "getEnvironmentVariable"),
        0,
        move(getEnvironmentVariableLambda));

    jsi::Object object = jsi::Object(rt);

    object.setProperty(rt, jsi::PropNameID::forAscii(rt, "getEnvironmentVariable"), move(getEnvironmentVariable));

    rt.global().setProperty(rt, "RNEnvJs", move(object));
}

void cleanUpSequel() {}
