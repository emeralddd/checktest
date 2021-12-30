const fs = require('fs')
const { execFileSync } = require('child_process')
const config = require('./config.json')
const {readdir} = require('fs/promises')

const findCPP = async () => {
    const files = await readdir(`./`)
    const cppfiles = files.filter(file => file.split('.').pop() === 'cpp')
    for(let file of cppfiles) {
        file = file.split('.cpp')[0]
        if(file !== 'inputRandom' && file !== 'outputSolve') {
            return file
        }
    }
}

const compilie = (fileName) => {
    execFileSync('g++',['-g','-std=c++14',`${fileName}.CPP`,'-o',`${fileName}.exe`])
}

const compilieTestGen = async () => {
    compilie('inputRandom')
    compilie('outputSolve')
}

const run = async () => {
    const problemName = await findCPP()
    if(problemName==='!') {
        console.log(`Khong tim duoc bai tap!`)
        return
    }
    console.log(`Da phat hien bai lam: ${problemName}`)
    fs.writeFileSync('config.txt',problemName)

    console.log(`Tao file RUN he thong!`)
    await compilieTestGen()

    console.log(`Compiling ${problemName}.CPP`)
    compilie(problemName)
    console.log(`Bien dich thanh cong!`)

    for(let i=1; i<=config.tests; i++) {
        console.log(`Dang kiem tra Test ${i}`)
        execFileSync(`./inputRandom`)
        execFileSync(`./outputSolve`)
        execFileSync(`./${problemName}`)

        const judgeOut = fs.readFileSync(`sampleOutput.txt`, 'utf-8')
        const candidateOut = fs.readFileSync(`${problemName}.OUT`, 'utf-8')

        if(judgeOut === candidateOut) {
            console.log(`Test ${i} passed!`)
        } else {
            console.log(`Test ${i} failed!`)
            return
        }
    }

    console.log(`Fully passed!`)
}

run()