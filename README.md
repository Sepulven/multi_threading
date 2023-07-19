# 🧵 Threads in C 🧵
    
Threads are the ideia of dividing a process into multiple threads that can run simultaneosly with other threads.
It may be correlated to workers in a kitchen.

## Advantages

- They run in parallel improving performance;
- They can share the same address space of the process and the environment;
- Priority can be assigned to the threads;
- Faster context switching;
- Communication is easy since the threads share the same memory space;


## Explaining a few functions:

- **pthread_create**
`
int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg);
`

  * pthread_create creates a new thread and starts its execution in the function specified by start_routine.
  * pthread_create creates a new thread and starts its execution in the function specified by start_routine.
  * The thread identifier is stored in the location pointed to by thread
  * The attr parameter can be used to specify thread attributes. You can pass NULL to use the default attributes.
  * The start_routine is the function that will be executed by the new thread.
  * The arg parameter is an argument passed to the start_routine function.
  
- **pthread_join**
`
int pthread_join(pthread_t thread, void** retval);
`

  * pthread_join suspends the calling thread until the target thread (specified by thread) terminates.
  * pthread_create creates a new thread and starts its execution in the function specified by start_routine.
  * If the target thread has already terminated, pthread_join returns immediately.
  * If the retval parameter is not NULL, the exit status of the target thread will be stored in the location pointed to by retval.

  
- **pthread_detach**
`
int pthread_detach(pthread_t thread);
`

  * pthread_detach marks the specified thread as "detached," allowing its resources to be automatically released when it terminates.
  * A detached thread's resources are reclaimed by the system without the need for an explicit pthread_join call.
  * Once a thread is detached, you cannot join it or obtain its exit status using pthread_join.

  
- **pthread_mutext_init**
`
int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);
`

  * pthread_mutex_init initializes a mutex object pointed to by mutex.
  * The attr parameter can be used to specify mutex attributes. You can pass NULL to use the default attributes.

- **pthread_mutex_lock**
`
int pthread_mutex_lock(pthread_mutex_t* mutex);
`

 * pthread_mutex_lock acquires a lock on the mutex pointed to by mutex.
 * If the mutex is already locked by another thread, the calling thread will be blocked until the mutex becomes available.

- **pthread_mutex_unlock**
`
int pthread_mutex_unlock(pthread_mutex_t* mutex);
`

  * pthread_mutex_unlock releases the lock on the mutex pointed to by mutex.
  * It allows other threads to acquire the mutex and enter the critical section safely.

- **pthread_mutext_destroy**
`
int pthread_mutex_destroy(pthread_mutex_t* mutex);
`

  * pthread_mutex_destroy destroys the mutex object pointed to by mutex.
  * It releases any resources associated with the mutex.
  * The mutex should not be destroyed while it is still in use or locked by other threads. Make sure to unlock it before destroying.
## Task List

- [ ] Add steroids to fractol using threads to calculate the values in the point.
Take advantage of long double to burn it on fire 🔥
- [ ] Understand how semaphores works.


> Notes made by Arthur Aguiar https://github.com/Sepulven
