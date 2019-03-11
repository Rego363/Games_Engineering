import java.util.LinkedList;

public class Threadexample
{
    public static void main(String[] args)
                        throws InterruptedException
    {
        final PC pc = new PC();

        Thread player = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                try
                {
                    pc.produce();
                }
                catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        });

        Thread npc = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                try
                {
                    pc.consume();
                }
                catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        });

        player.start();
        npc.start();

        player.join();
        npc.join();
    }

    public static class PC
    {
        LinkedList<Integer> list = new LinkedList<>();
        int capacity = 2;

        public void produce() throws InterruptedException
        {
            int shared = 0;
            while (true)
            {
                synchronized (this)
                {
                    while (list.size()==capacity)
                        wait();

                    System.out.println("Player produced-"
                                                  + shared);

                    list.add(shared++);

                    notify();

                    Thread.sleep(1000);
                }
            }
        }

        public void consume() throws InterruptedException
        {
            while (true)
            {
                synchronized (this)
                {
                    while (list.size()==0)
                        wait();

                    int shared = list.removeFirst();

                    System.out.println("NPC consumed-"
                                                    + shared);

                    notify();

                    Thread.sleep(1000);
                }
            }
        }
    }
} 
