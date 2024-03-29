import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun insertTab(bw: BufferedWriter, tabs: Int) {
	if (tabs <= 0)
		return

	for (i in 1..tabs)
		bw.write("____")
	return
}

fun chat(br: BufferedReader, bw: BufferedWriter, cnt: Int, tab: Int) {
	if (tab == 0)
		bw.write("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n")

	if (cnt >= 1) {
		insertTab(bw, tab)
		bw.write("\"재귀함수가 뭔가요?\"\n")
		insertTab(bw, tab)
		bw.write("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n")
		insertTab(bw, tab)
		bw.write("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n")
		insertTab(bw, tab)
		bw.write("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n")
		chat(br, bw, cnt - 1, tab + 1)
		insertTab(bw, tab)
		bw.write("라고 답변하였지.\n")
	} else if (cnt == 0) {
		insertTab(bw, tab)
		bw.write("\"재귀함수가 뭔가요?\"\n")
		insertTab(bw, tab)
		bw.write("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n")
		insertTab(bw, tab)
		bw.write("라고 답변하였지.\n")
	}
	return
}

fun main() {
	val br = BufferedReader(InputStreamReader(System.`in`))
	val bw = BufferedWriter(OutputStreamWriter(System.out))

	chat(br, bw, br.readLine().toInt(), 0)

	bw.flush()
	bw.close()
	br.close()
}