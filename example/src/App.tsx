import * as React from 'react';

import { StyleSheet, View, Text, Platform } from 'react-native';
import { getEnvironmentVariable } from 'react-native-env-js';

export default function App() {
  const [envVariable, setEnvVariable] = React.useState<string | null>();

  React.useEffect(() => {
    setEnvVariable(
      getEnvironmentVariable(
        Platform.select({ ios: 'HOME', default: 'ANDROID_BOOTLOGO' })
      )
    );
  }, []);

  return (
    <View style={styles.container}>
      <Text>Result: {envVariable}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
