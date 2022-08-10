import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun main() {
	val br = BufferedReader(InputStreamReader(System.`in`))
	val bw = BufferedWriter(OutputStreamWriter(System.out))

	val total: Int = br.readLine().toInt()
	var n: Int = br.readLine().toInt()
	var sum_total: Int = 0
	var token: StringTokenizer
	var price: Int; var cnt: Int

	for (i in 1..n) {
		token = StringTokenizer(br.readLine())
		price = token.nextToken().toInt()
		cnt = token.nextToken().toInt()
		sum_total += price * cnt
	}
	
	bw.write(if (total == sum_total) "Yes" else "No")

	bw.flush()
	bw.close()
	br.close()
}
