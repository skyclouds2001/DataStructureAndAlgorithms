const readline = require('readline')

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})

rl.on('line', function (line: string) {
    const commands = line.trim().split(';').filter(v => v.length > 0)

    const PRODUCT_NAMES = ['A1', 'A2', 'A3', 'A4', 'A5', 'A6'] as const
    const PRODUCT_PRICES = [2, 3, 4, 5, 8, 6] as const
    const MONEY_NAMES = [1, 2, 5, 10] as const
    const PRODUCT_COUNT = 6
    const MONEY_COUNT = 4

    const products = new Map<string, Record<'price' | 'amount', number>>()
    const moneys = new Map<number, number>()
    let balance = 0

    for (let i = 0; i < PRODUCT_COUNT; ++i) {
        products.set(PRODUCT_NAMES[i], {
            price: PRODUCT_PRICES[i],
            amount: 0,
        })
    }
    for (let j = 0; j < MONEY_COUNT; ++j) {
        moneys.set(MONEY_NAMES[j], 0)
    }

    for (const command of commands) {
        const cmds = command.trim().split(' ')
        const cmd = cmds[0].trim()

        switch (cmd) {
            case 'r': {
                const pros = cmds[1].trim().split('-').map(v => Number.parseInt(v))
                const mons = cmds[2].trim().split('-').map(v => Number.parseInt(v))

                for (let i = 0; i < PRODUCT_COUNT; ++i) {
                    products.set(PRODUCT_NAMES[i], {
                        price: PRODUCT_PRICES[i],
                        amount: pros[i],
                    })
                }
                for (let j = 0; j < MONEY_COUNT; ++j) {
                    moneys.set(MONEY_NAMES[j], mons[j])
                }

                console.log('S001:Initialization is successful')

                break
            }
            case 'p': {
                const mon = Number.parseInt(cmds[1].trim())
                const count = moneys.get(mon)

                if (count == null) {
                    console.log('E002:Denomination error')
                    break
                }
                if (mon !== 1 && mon !== 2 && mon > moneys.get(1)! * 1 + moneys.get(2)! * 2) {
                    console.log('E003:Change is not enough, pay fail')
                    break
                }
                if (Array.from(products).reduce((sum, val) => (sum + val[1].amount), 0) === 0) {
                    console.log('E005:All the goods sold out')
                    break
                }

                balance += mon
                moneys.set(mon, count + 1)
                console.log(`S002:Pay success,balance=${balance}`)

                break
            }
            case 'b': {
                const pro = cmds[1].trim()
                const product = products.get(pro)

                if (product == null) {
                    console.log('E006:Goods does not exist')
                    break
                }
                if (product.amount === 0) {
                    console.log('E007:The goods sold out')
                    break
                }
                if (balance < product.price) {
                    console.log('E008:Lack of balance')
                    break
                }

                balance -= product.price
                products.set(pro, {
                    price: product.price,
                    amount: product.amount - 1,
                })
                console.log(`S003:Buy success,balance=${balance}`)

                break
            }
            case 'c': {
                if (balance === 0) {
                    console.log('E009:Work failure')
                    break
                }

                const return_moneys = new Map<number, number>()

                for (const money of MONEY_NAMES) {
                    return_moneys.set(money, 0)
                }

                for (const money of Array.from(moneys).sort((a, b) => b[0] - a[0])) {
                    while (money[0] <= balance && money[1] > 0) {
                        balance -= money[0]
                        moneys.set(money[0], money[1] - 1)
                        return_moneys.set(money[0], return_moneys.get(money[0])! + 1)
                    }
                }

                for (const money of Array.from(return_moneys)) {
                    console.log(`${money[0]} yuan coin number=${money[1]}`)
                }

                balance = 0

                break
            }
            case 'q': {
                const type = Number.parseInt(cmds[1].trim())

                switch (type) {
                    case 0: {
                        const pros = Array.from(products)
                            .map((v, i) => ([v[0], v[1].price, v[1].amount] as const))
                            .sort((a, b) => (a[2] < b[2] || a[2] === b[2] && a[0] > b[0] ? 1 : -1))
                        for (const product of pros) {
                            console.log(product.join(' '))
                        }
                        break
                    }
                    case 1: {
                        const mons = Array.from(moneys)
                            .sort((a, b) => (a[0] > b[0] ? 1 : -1))
                        for (const money of mons) {
                            console.log(`${money[0]} yuan coin number=${money[1]}`)
                        }
                        break
                    }
                    default: {
                        console.log('E010:Parameter error')
                        break
                    }
                }

                break
            }
            default: {
                console.log('E010:Parameter error')
                break
            }
        }
    }
})
