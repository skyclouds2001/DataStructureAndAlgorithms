const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data: string) {
  const cmd = data.trim()

  if (!cmd.includes(' ')) {
    if (single_str.source.startsWith(cmd)) {
      console.log(single_str.target)
      return
    } else {
      console.log(unknown)
      return
    }
  }

  const [cmd1, cmd2] = cmd.split(' ').filter(cmd => cmd)

  let matches = double_str.filter(str => str.source[0].startsWith(cmd1))
  if (matches.length === 0) {
    console.log(unknown)
    return
  }
  matches = matches.filter(str => str.source[1].startsWith(cmd2))
  if (matches.length !== 1) {
    console.log(unknown)
    return
  }
  console.log(matches[0].target)
  return
})

const single_str = {
  source: 'reset',
  target: 'reset what',
}

const double_str = [
  {
    source: ['reset', 'board'],
    target: 'board fault',
  },
  {
    source: ['board', 'add'],
    target: 'where to add',
  },
  {
    source: ['board', 'delete'],
    target: 'no board at all',
  },
  {
    source: ['reboot', 'backplane'],
    target: 'impossible',
  },
  {
    source: ['backplane', 'abort'],
    target: 'install first',
  },
]

const unknown = 'unknown command'
