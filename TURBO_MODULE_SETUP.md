# React Native Minimizer - TurboModule Configuration

This module now supports React Native's New Architecture (TurboModules). Below are the configuration steps required to enable TurboModule support.

## Prerequisites

- React Native 0.68+
- New Architecture enabled in your React Native project

## Configuration

### 1. Enable New Architecture

In your `android/gradle.properties`:
```properties
newArchEnabled=true
```

In your `ios/Podfile`:
```ruby
use_frameworks! :linkage => :static
$RNNewArchEnabled = true
```

### 2. Android Setup

No additional configuration needed. The module automatically detects the new architecture.

### 3. iOS Setup

No additional configuration needed. The module automatically detects the new architecture.

## Usage

The API remains the same regardless of architecture:

```typescript
import { minimize, goBack, exit } from '@kangfenmao/react-native-minimizer';

// Minimize the app
minimize();

// Go back to previous app
goBack();

// Exit the app
exit();
```

## TurboModule Benefits

- **Performance**: Direct JSI communication without the bridge
- **Type Safety**: Better TypeScript support
- **Future-proof**: Aligned with React Native's architectural direction

## Backwards Compatibility

This module maintains full backwards compatibility with the old architecture. When new architecture is not enabled, it automatically falls back to the traditional NativeModules approach.
