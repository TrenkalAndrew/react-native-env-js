export type TResult = string | null;

type TRNEnvJS = {
  getEnvironmentVariable: (variableName: string) => TResult;
};

declare global {
  var RNEnvJs: TRNEnvJS;
}
