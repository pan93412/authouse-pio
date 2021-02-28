# Guide to contribute AuthouseLight

## Headers

```cpp
/**
 * <Package Name>
 *   @brief <Brief description of your package>
 *   @author <Your name>
 *   @date YYYY-MM-DD (e.g. 2020-12-14)
 */
```

## Package Name

It should be formed in:

```plain
Authouse.Communication.SerialCommunication
```

`Authouse` is the main package, and `Communication` is
the sub one, so on.

## Include Guard

The format should be:

```cpp
#ifndef AH_<your package name without Authouse. but all dots are replaced with _>
#define AH_<your package name without Authouse. but all dots are replaced with _>
// your code goes here
#endif
```

For example, if your package name is `Authouse.Communication.SerialCommunication`,
then the include guard should be:

```cpp
#ifndef AH_Communication_SerialCommunication
#define AH_Communication_SerialCommunication
// your code goes here
#endif
```
