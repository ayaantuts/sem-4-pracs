import java.util.*;

class Semaphore {
	private int count;
	public Semaphore(int count) {
		this.count = count;
	}
	
	public synchronized void down() {
		while(count == 0) {
			try {
				wait();
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		count--;
	}
	
	public synchronized void signal() {
		count++;
		notify();
	}
}

class Producer extends Thread {
	ProducerConsumer pc;
	Semaphore mutex, empty, full;
	Scanner sc = new Scanner(System.in);
	int in = 0, num;
	public Producer(ProducerConsumer pc, Semaphore mutex, Semaphore empty, Semaphore full) {
		this.pc = pc;
		this.mutex = mutex;
		this.empty = empty;
		this.full = full;
	}
	
	public void run() {
		while(true) {
		// for (int i = 0; i < 10; i++) {
			empty.down();
			mutex.down();
			// System.out.print("Enter a number: ");
			// num = sc.nextInt();
			num = (int)(Math.random() * 1000) + 1;
			pc.buffer[in] = num;
			System.out.println("Produced: " + pc.buffer[in]);
			in = (in + 1) % pc.size;
			System.out.println("Producer Buffer: " + Arrays.toString(pc.buffer));
			mutex.signal();
			full.signal();
		}
	}
}

class Consumer extends Thread {
	ProducerConsumer pc;
	Semaphore mutex, empty, full;
	int out = 0;
	public Consumer(ProducerConsumer pc, Semaphore mutex, Semaphore empty, Semaphore full) {
		this.pc = pc;
		this.mutex = mutex;
		this.empty = empty;
		this.full = full;
	}
	
	public void run() {
		while(true) {
		// for (int i = 0; i < 10; i++) {
			full.down();
			mutex.down();
			System.out.println("Consumed: " + pc.buffer[out]);
			pc.buffer[out] = 0;
			out = (out + 1) % pc.size;
			System.out.println("Consumer Buffer: " + Arrays.toString(pc.buffer));
			mutex.signal();
			empty.signal();
		}
	}
}

public class ProducerConsumer {
	int buffer[];
	int size;
	public static void main(String[] args) {
		ProducerConsumer pc = new ProducerConsumer();
		pc.size = 5;
		pc.buffer = new int[pc.size];
		Semaphore mutex = new Semaphore(1);
		Semaphore empty = new Semaphore(pc.size);
		Semaphore full = new Semaphore(0);
		Producer p = new Producer(pc, mutex, empty, full);
		Consumer c = new Consumer(pc, mutex, empty, full);
		p.start();
		c.start();

		try {
			c.join();
			p.join();
		} catch(InterruptedException e) {
			e.printStackTrace();
		}
	}
}