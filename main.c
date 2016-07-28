#include <stdio.h>
#include <assert.h>
#include "threadlib.h"

			   
#ifdef TESTING 
/* few threads to play around with
 */
void thread1(void);
void thread2(void); 

void thread1(void)
{
  int i = 1;
  for(;i<100;) {
    printf("%s: count = %d\n",__func__,i++);
    yield(); 
  }
  delete_thread();
  assert(0);
}

void thread2(void)
{
  int i = -100;
  for(;i<0;) {
    printf("%s: count = %d\n",__func__,i++);
    yield();
  }
  delete_thread();
  assert(0);
}

int main(void)
{ 
  printf("Creating thread 1\n");
  assert(!create_thread(thread2));

  printf("Creating thread 2\n");
  assert(!create_thread(thread1));

  stop_main(); /* give up the CPU */
  assert(0); /* you should not come back */

}
#else /* real code
       * this is what we'll test/mark
       */

int count = 1;

#define MAX 25 /* how many threads to create */

#define COUNT(x) x*100000

void simple_thread(void); /* want to create many instance of
			   * this. 
			   */

void simple_thread(void)
{
  int i, myID, sleep;
  
  myID = count;

  count ++; /* for the next thread 
	     * It is shared, do I need to lock??? A lock is not necessary. Yielding is collaborative. So cant be pre-empted at the middle
	     */

  for(i=myID; i<MAX;i++) {
    /* print something, sleep for a while and yield */
    printf("I'm %s %d: Count=%d\n",__func__,myID,i);
    for(sleep=-COUNT(myID); sleep < COUNT(myID); sleep++);
    yield();
  }

  delete_thread(); /* die */
  printf("Make NO_THREADS <= MAX\n");
  assert(0); /* I should not be running */
}

#define NO_THREADS 25
/* NO_THREADS <= MAX */

int main(void)
{ 

  int i; 
  for(i=0; i < NO_THREADS; i++) 
  {
    assert(!create_thread(simple_thread));
  }
  stop_main(); /* give up the CPU */
  assert(0); /* you should not come back */

}
#endif
