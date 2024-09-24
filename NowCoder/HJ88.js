const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data) {
  const cards1 = data.trim().split('-').at(0).trim().split(' ')
  const cards2 = data.trim().split('-').at(1).trim().split(' ')

  const cardType1 = getCardType(cards1)
  const cardType2 = getCardType(cards2)

  let cmp = 0
  if (cardType1 === cardType2) {
    if (cardType1 === CARD_TYPE.ERROR && cardType2 === CARD_TYPE.ERROR) {
      cmp = 0
    } else if (cardType1 === CARD_TYPE.PAIR && cardType2 === CARD_TYPE.PAIR) {
      if (CARD_VALUE[cards1[0]] + CARD_VALUE[cards1[1]] > CARD_VALUE[cards2[0]] + CARD_VALUE[cards2[1]]) {
        cmp = 1
      } else {
        cmp = 2
      }
    } else if (cardType1 === CARD_TYPE.BOMB && cardType2 === CARD_TYPE.BOMB) {
      if (CARD_VALUE[cards1.at(0)] > CARD_VALUE[cards2.at(0)]) {
        cmp = 1
      } else {
        cmp = 2
      }
    } else if (cardType1 === CARD_TYPE.TRIPLE && cardType2 === CARD_TYPE.TRIPLE) {
      if (CARD_VALUE[cards1.at(0)] > CARD_VALUE[cards2.at(0)]) {
        cmp = 1
      } else {
        cmp = 2
      }
    } else if (cardType1 === CARD_TYPE.CONSECUTIVE && cardType2 === CARD_TYPE.CONSECUTIVE) {
      if (CARD_VALUE[cards1.at(0)] > CARD_VALUE[cards2.at(0)]) {
        cmp = 1
      } else {
        cmp = 2
      }
    } else if (cardType1 === CARD_TYPE.DOUBLE && cardType2 === CARD_TYPE.DOUBLE) {
      if (CARD_VALUE[cards1.at(0)] > CARD_VALUE[cards2.at(0)]) {
        cmp = 1
      } else {
        cmp = 2
      }
    } else if (cardType1 === CARD_TYPE.SINGLE && cardType2 === CARD_TYPE.SINGLE) {
      if (CARD_VALUE[cards1.at(0)] > CARD_VALUE[cards2.at(0)]) {
        cmp = 1
      } else {
        cmp = 2
      }
    }
  } else {
    if (cardType1 === CARD_TYPE.ERROR || cardType2 === CARD_TYPE.ERROR) {
      cmp = 0
    } else if (cardType1 === CARD_TYPE.PAIR) {
      cmp = 1
    } else if (cardType2 === CARD_TYPE.PAIR) {
      cmp = 2
    } else if (cardType1 === CARD_TYPE.BOMB) {
      cmp = 1
    } else if (cardType2 === CARD_TYPE.BOMB) {
      cmp = 2
    } else {
      cmp = 0
    }
  }

  if (cmp === 0) {
    console.log('ERROR')
  } else if (cmp === 1) {
    console.log(cards1.join(' '))
  } else if (cmp === 2) {
    console.log(cards2.join(' '))
  }
})

function getCardType(cards) {
  let type = null
  switch (cards.length) {
    case 4:
      type = CARD_TYPE.BOMB
      break
    case 2:
      if (cards.every(card => CARD_NAME.JOKER === card || CARD_NAME.joker === card)) {
        type = CARD_TYPE.PAIR
      } else {
        type = CARD_TYPE.DOUBLE
      }
      break
    case 5:
      type = CARD_TYPE.CONSECUTIVE
      break
    case 3:
      type = CARD_TYPE.TRIPLE
      break
    case 1:
      type = CARD_TYPE.TRIPLE
      break
    default:
      type = CARD_TYPE.SINGLE
      break
  }
  return type
}

const CARD_NAME = {
  '3': '3',
  '4': '4',
  '5': '5',
  '6': '6',
  '7': '7',
  '8': '8',
  '9': '9',
  '10': '10',
  'J': 'J',
  'Q': 'Q',
  'K': 'K',
  'A': 'A',
  '2': '2',
  'joker': 'joker',
  'JOKER': 'JOKER',
}

const CARD_VALUE = {
  '3': 1,
  '4': 2,
  '5': 3,
  '6': 4,
  '7': 5,
  '8': 6,
  '9': 7,
  '10': 8,
  'J': 9,
  'Q': 10,
  'K': 11,
  'A': 12,
  '2': 13,
  'joker': 14,
  'JOKER': 15,
}

const CARD_TYPE = {
  SINGLE: 1,
  DOUBLE: 2,
  CONSECUTIVE: 3,
  TRIPLE: 4,
  BOMB: 5,
  PAIR: 6,
  ERROR: 0,
}
