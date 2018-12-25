```
# findingsea @ LAWRENCELIN-MB2 in ~/Workspace/ctest [17:13:56]
$ g++ -c -fPIC -o ctest.o ctest.cpp

# findingsea @ LAWRENCELIN-MB2 in ~/Workspace/ctest [17:14:27] C:126
$ g++ -shared -o libctest.so ctest.o

# findingsea @ LAWRENCELIN-MB2 in ~/Workspace/ctest [17:15:01]
$ g++ -o ctest_main ctest_main.cpp -lctest -L.

# findingsea @ LAWRENCELIN-MB2 in ~/Workspace/ctest [17:17:34]
$ ./ctest_main
My C Test is running.
```