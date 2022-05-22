#include "react-native-env-js.h"
#include <iostream>

using namespace facebook;
using namespace std;

void installSequel(jsi::Runtime &rt) {
    cout << "Installing JSI binding" << endl;
    
    jsi::Function multiply = jsi::Function::createFromHostFunction(
       rt,
       jsi::PropNameID::forAscii(rt, "multiply"),
       0,
       [](jsi::Runtime &rt,
          const jsi::Value & thisValue,
          const jsi::Value *args,
          size_t count) -> jsi::Value {
              return jsi::Value(42);
          }
       );
    
    rt.global().setProperty(rt, "multiply", multiply);
}

void cleanUpSequel() {
    
}
