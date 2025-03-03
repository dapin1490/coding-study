import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun firstUpper(txt: String): String {
	return txt.substring(0, 1).uppercase() + txt.substring(1)
}

fun main() {
	val br = BufferedReader(InputStreamReader(System.`in`))
	val bw = BufferedWriter(OutputStreamWriter(System.out))

	val n: Int = br.readLine().toInt()

	repeat(n) {
		bw.write(firstUpper(br.readLine()) + "\n")
	}

	bw.flush()
	bw.close()
	br.close()
}
