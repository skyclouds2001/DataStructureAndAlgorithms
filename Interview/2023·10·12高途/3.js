function parseArrToTree(list) {
    const map = new Map()
    for (const v of list) {
        map.set(v.id, v)
    }

    function generate(id) {
        return (map.get(id).children ?? []).map(v => ([id, ...generate(v)]))
    }

    // 假定根节点为 1
    return generate(1)
}
