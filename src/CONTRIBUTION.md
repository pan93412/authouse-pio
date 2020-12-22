## Headers
```cpp
/**
 * <Package Name>
 *   <Brief description of your package>
 *   @author <Your name>
 *   @date YYYY-MM-DD (e.g. 2020-12-14)
 */
```

## Package Name
It should be formed in:

```
Authouse.Communication.SerialCommunication
```

`Authouse` is the main package, and `Communication` is
the sub one, so on.

## Include Guard
The format should be:

```cpp
#ifndef AH_sha1(<your package name>)
#define AH_sha1(<your package name>)
// your code goes here
#endif
```

For example, if your package name is `Authouse.Communication.SerialCommunication`,
then the include guard should be:

```cpp
#ifndef AH_185326bdfe0235150e5c6cc7116a4b311dc64228
#define AH_185326bdfe0235150e5c6cc7116a4b311dc64228
// your code goes here
#endif
```