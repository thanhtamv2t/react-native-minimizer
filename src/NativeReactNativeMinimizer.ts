import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  minimize(): void;
  goBack(): void;
  exit(): void;
}

export default TurboModuleRegistry.getEnforcing<Spec>('ReactNativeMinimizer');
