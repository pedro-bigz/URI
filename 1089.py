def main ():
    while True:
        try:
            n = int(input ())

            if n == 0:
                break

            count = 0
            h = input().split(" ")

            fst = int(h[0])
            scd = int(h[1])

            for i in range(1, len(h) - 1):
                last = int(h[i - 1])
                curr = int(h[i])
                next = int(h[i + 1])

                if curr > last and curr > next:
                    count += 1
                elif curr < last and curr < next:
                    count += 1

            if len(h) == 2 and fst != scd:
                count = 2

            else:
                if (next > curr and next > fst) or (next < curr and next < fst):
                    count += 1

                if (fst > scd and fst > next) or (fst < scd and fst < next):
                    count += 1

            print(count)

        except EOFError:
            break

main()
