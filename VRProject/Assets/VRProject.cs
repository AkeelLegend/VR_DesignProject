using System.Collections;
using UnityEngine;
using System.IO.Ports;

public class VRProject : MonoBehaviour {
	public float y;
	public float z;
	public float x;
	public float posX;
	public float posY;
	public float posZ;
	SerialPort serial = new SerialPort("COM3", 115200);

	// Use this for initialization
	void Start () {
		serial.Open ();
		serial.ReadTimeout = 2000;

	}

	// Update is called once per frame
	void Update () {
		if (!serial.IsOpen)
			serial.Open ();

		serial.Write ("a");
		float velX = int.Parse (serial.ReadLine ());
		serial.Write ("b");
		float velY = int.Parse (serial.ReadLine ());
		serial.Write ("c");
		float velZ = int.Parse (serial.ReadLine ());
		serial.Write ("d");
		float GyrX = int.Parse (serial.ReadLine ());
		serial.Write ("e");
		float GyrY = int.Parse (serial.ReadLine ());
		serial.Write ("f");
		float GyrZ = int.Parse (serial.ReadLine ());

		x += GyrX / 2620;
		y += GyrY / 2620;
		z += GyrX / 2620;

		posX += velX / 200;
		posY += velY / 200;
		posZ += velZ / 200;



		transform.localEulerAngles = new Vector3 (-x, -y, -z);
		transform.localPosition = new Vector3(posX, posY, posZ);
	}
}