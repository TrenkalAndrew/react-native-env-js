# react-native-env-js

Library for getting native environment variables on js side.
It may be usefull when you need to configure some code on js-side with using environment configurations.

For example - enable or disable storybook or another tools for internal build of your application.

at its core, the library uses jsi technology, which allows you to get rid of asynchronous calls, and also provides the fastest way to interact native side and js side of your application.

# Installation

```sh
npm install react-native-env-js
```

```sh
yarn add react-native-env-js
```

# Usage

```js
import { getEnvironmentVariable } from 'react-native-env-js';

// ...
const environmentVariableName = "HOME";

const home = getEnvironmentVariable(environmentVariableName);

// ...
```

# Methods

| method                 | description                                      | args                 | return type    |
|------------------------|--------------------------------------------------|----------------------|----------------|
| getEnvironmentVariable | returns an environment variable from native side | variableName: string | string \| null |

# License

MIT
