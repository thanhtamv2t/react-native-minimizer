# @kangfenmao/react-native-minimizer

Minimize or redirect back to previous APP, works on Android And iOS.

✨ **Now supports React Native's New Architecture (TurboModules)** with full backwards compatibility!

## Installation

```sh
npm install @kangfenmao/react-native-minimizer
```

## Usage

```js
import Minimizer from '@kangfenmao/react-native-minimizer';

// Put the APP in the background.
Minimizer.minimize()

// Exit the APP
Minimizer.exit()

// Return to the previous APP.
Minimizer.goBack()
```

## TurboModule Support

This library supports React Native's New Architecture (TurboModules) for improved performance and type safety. See [TURBO_MODULE_SETUP.md](TURBO_MODULE_SETUP.md) for configuration details.

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
