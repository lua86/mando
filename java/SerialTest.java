import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;
import java.util.Enumeration;

public class SerialTest implements SerialPortEventListener {
	SerialPort serialPort;
	/** Lista de nombres frecuentes para puertos de serie. */
	private static final String PORT_NAMES[] = { "/dev/tty.usbserial-A9007UX1", // OSX
																				// OS
																				// X
			"/dev/ttyUSB0", "/dev/ttyUSB1", "/dev/ttyACM0", "/dev/ttyACM1", // GNU/Linux
			"COM0", "COM1", "COM2", "COM3", // Basura
	};
	/**
	 * Un BufferedReader que será alimentado por un InputStreamReader transformando
	 * bytes a caracteres haciendo los resultados mostrados independientes de la tabla de códigos
	 */
	private BufferedReader input;
	private OutputStream output;
	/** Milisegundos a esperar al puerto a abrirse */
	private static final int TIME_OUT = 2000;
	/** Baudios por defecto para el puerto serie. */
	private static final int DATA_RATE = 9600;

	public void initialize() {
		CommPortIdentifier portId = null;
		Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();

		// Identifica la primera instancia de puerto de serie en PORT_NAMES.
		while (portEnum.hasMoreElements()) {
			CommPortIdentifier currPortId = (CommPortIdentifier) portEnum
					.nextElement();
			for (String portName : PORT_NAMES) {
				if (currPortId.getName().equals(portName)) {
					portId = currPortId;
					break;
				}
			}
		}
		System.out.println("Puerto: ");
		System.out.println(portId);
		System.out.println("");
		if (portId == null) {
			System.out.println("Puerto de serie no conectado, nombre no en la lista, o falta de privilegios.");
			return;
		}

		try {
			// abre el puerto de serie, y usa el nombre de la clase para el appName.
			serialPort = (SerialPort) portId.open(this.getClass().getName(),
					TIME_OUT);

			// Inicializa los parámetros del puerto de serie
			serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8,
					SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);

			// Abre los flujos de datos
			input = new BufferedReader(new InputStreamReader(
					serialPort.getInputStream()));
			output = serialPort.getOutputStream();

			// Añade EventListener
			serialPort.addEventListener(this);
			serialPort.notifyOnDataAvailable(true);
		} catch (Exception e) {
			System.err.println(e.toString());
		}
	}

	/**
	 * Esto debería ser llamado al parar de usar el puerto.
	 * Sirve para cerrar el puerto, evitando bloqueos en sistemas basados en UNIX.
	 */
	public synchronized void close() {
		if (serialPort != null) {
			serialPort.removeEventListener();
			serialPort.close();
		}
	}

	 // Maneja un evento en el puerto de serie. Lee los datos, imprímelos y pulsa las teclas.

	public synchronized void serialEvent(SerialPortEvent oEvent) {
		if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
			try {
				String inputLine = input.readLine();
				// Select
				if (inputLine.equals("Select")) {
					System.out.println("Select");
					try {
						Robot robot = new Robot();
						robot.keyPress(KeyEvent.VK_E);
						robot.delay(200);
						robot.keyRelease(KeyEvent.VK_E);
					} catch (AWTException e) {
						e.printStackTrace();
					}
				}
				// Start
				if (inputLine.equals("Start")) {
					System.out.println("Start");
					try {
						Robot robot = new Robot();
						robot.keyPress(KeyEvent.VK_T);
						robot.delay(200);
						robot.keyRelease(KeyEvent.VK_T);
					} catch (AWTException e) {
						e.printStackTrace();
					}
				}
				// Down
				if (inputLine.equals("Down")) {
					System.out.println("Down");
					try {
						Robot robot = new Robot();
						robot.keyPress(KeyEvent.VK_DOWN);
						robot.delay(100);
						robot.keyRelease(KeyEvent.VK_DOWN);
					} catch (AWTException e) {
						e.printStackTrace();
					}
				}
				// UP
				if (inputLine.equals("UP")) {
					System.out.println("UP");
					try {
						Robot robot = new Robot();
						robot.keyPress(KeyEvent.VK_UP);
						robot.delay(100);
						robot.keyRelease(KeyEvent.VK_UP);
					} catch (AWTException e) {
						e.printStackTrace();
					}
				}
                                // Left
                                if (inputLine.equals("Left")) {
                                        System.out.println("Left");
                                        try {
                                                Robot robot = new Robot();
                                                robot.keyPress(KeyEvent.VK_LEFT);
                                                robot.delay(100);
                                                robot.keyRelease(KeyEvent.VK_LEFT);
                                        } catch (AWTException e) {
                                                e.printStackTrace();
                                        }
                                }
                                // Right
                                if (inputLine.equals("Right")) {
                                        System.out.println("Right");
                                        try {
                                                Robot robot = new Robot();
                                                robot.keyPress(KeyEvent.VK_RIGHT);
                                                robot.delay(100);
                                                robot.keyRelease(KeyEvent.VK_RIGHT);
                                        } catch (AWTException e) {
                                                e.printStackTrace();
                                        }
                                }
                                // L
                                if (inputLine.equals("L")) {
                                        System.out.println("L");
                                        try {
                                                Robot robot = new Robot();
                                                robot.keyPress(KeyEvent.VK_L);
                                                robot.delay(100);
                                                robot.keyRelease(KeyEvent.VK_L);
                                        } catch (AWTException e) {
                                                e.printStackTrace();
                                        }
                                }
                                // R
                                if (inputLine.equals("R")) {
                                        System.out.println("R");
                                        try {
                                                Robot robot = new Robot();
                                                robot.keyPress(KeyEvent.VK_R);
                                                robot.delay(100);
                                                robot.keyRelease(KeyEvent.VK_R);
                                        } catch (AWTException e) {
                                                e.printStackTrace();
                                        }
                                }
                                // A
                                if (inputLine.equals("A")) {
                                        System.out.println("A");
                                        try {
                                                Robot robot = new Robot();
                                                robot.keyPress(KeyEvent.VK_A);
                                                robot.delay(100);
                                                robot.keyRelease(KeyEvent.VK_A);
                                        } catch (AWTException e) {
                                                e.printStackTrace();
                                        }
                                }
                                // B
                                if (inputLine.equals("B")) {
                                        System.out.println("B");
                                        try {
                                                Robot robot = new Robot();
                                                robot.keyPress(KeyEvent.VK_B);
                                                robot.delay(100);
                                                robot.keyRelease(KeyEvent.VK_B);
                                        } catch (AWTException e) {
                                                e.printStackTrace();
                                        }
                                }






			} catch (Exception e) {
				System.err.println(e.toString());
			}
		}
		if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE) {

		}
	}

	public static void main(String[] args) throws Exception {
		SerialTest main = new SerialTest();
		main.initialize();
		Thread t = new Thread() {
			public void run() {
				// La siguiente línea mantendrá la clase activa 1000 segundos,
				// Esperando eventos y respondiéndolos.
				try {
					Thread.sleep(1000000);
				} catch (InterruptedException ie) {
				}
			}
		};
		t.start();
		System.out.println("- Started -");
		System.out.println("");
	}
}