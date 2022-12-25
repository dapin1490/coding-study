import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.text.DecimalFormat

fun detectChar(bw: BufferedWriter, text: String) {
	val df = DecimalFormat("#.#")
	val totalLen: Int = text.length
	var detectedChar = 0

	for (c in text) {
		if (c != '#')
			detectedChar++
	}

	bw.write("Efficiency ratio is ${df.format(detectedChar.toDouble() / totalLen.toDouble() * 100)}%.\n")
}

fun main() {
	val br = BufferedReader(InputStreamReader(System.`in`))
	val bw = BufferedWriter(OutputStreamWriter(System.out))

	val n: Int = br.readLine().toInt()

	repeat(n) {
		var text = ""

		while (true) {
			val line = br.readLine()
			if (line != "" && line != null) {
				text += line
			} else break
		}

		detectChar(bw, text)
	}

	bw.flush()
	bw.close()
	br.close()
}
