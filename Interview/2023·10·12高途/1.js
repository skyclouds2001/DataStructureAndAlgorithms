class Company {
    constructor(fullName, ceo) {
        this.fullName = fullName
        this.ceo = ceo
    }

    greet() {
        console.log(`Welcome to ${this.fullName}`)
    }
}
