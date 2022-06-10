public class Deadlock {
    static Object lock1 = new Object();
    static Object lock2 = new Object();
    
    private static class ThreadOne extends Thread {
        public void run() {
            synchronized(lock1) {
                System.out.println("Thread One: lock1");
                
                try {
                    Thread.sleep(100);
                } catch(InterruptedException e) {
                    e.printStackTrace();
                }
            System.out.println("Thread One: Waiting for lock2");
            synchronized (lock2) {
               System.out.println("Thread One: No DeadLock");
            }
            }
        }
    }
    
     private static class ThreadTwo extends Thread {
      public void run() {
         synchronized (lock2) {
            System.out.println("Thread Two: Has  lock2");
            try { 
                Thread.sleep(100);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Thread Two: Waiting for lock1");
            synchronized (lock1) {
               System.out.println("Thread Two: No DeadLock");
            }
         }
      }
     }
     
     public static void main(String args[]) {
         ThreadOne threadOne = new ThreadOne();
         ThreadTwo threadTwo = new ThreadTwo();
         
         threadOne.start();
         threadTwo.start();
     }
}
