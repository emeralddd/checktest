const { execFileSync } = require('child_process')
const {readdir} = require('fs/promises')
const {existsSync, mkdirSync, copyFileSync, writeFileSync, readFileSync, openSync} = require('fs')
const path = require('path')

const findCPP = async () => {
    const files = await readdir(`./sources`)
    const cppfiles = files.filter(file => file.split('.').pop() === 'cpp')
    let res = '!'
    for(let file of cppfiles) {
        file = file.split('.cpp')[0]
        if(file !== 'inputRandom' && file !== 'outputSolve') {
            res=file
        }
    }
    return res
}

const compilie = (fileName) => {
    execFileSync('g++',['-g','-std=c++14',`./sources/${fileName}.CPP`,'-o',`./execute/${fileName}.exe`])
}

const compilieTestGen = async () => {
    compilie('inputRandom')
    compilie('outputSolve')
}

const checkExist = () => {
    if(!existsSync('./execute')) {
        mkdirSync('./execute')
    }
    
    if(!existsSync('./execute/config.txt')) {
        openSync('./execute/config.txt','w')
    }

    if(!existsSync('./settings')) {
        mkdirSync('./settings')
    }

    if(!existsSync('./settings/config.json')) {
        const sourceData = readFileSync(path.join(__dirname,'./default/config.json'), 'utf-8')
        writeFileSync('./settings/config.json', sourceData, 'utf-8')
    }

    if(!existsSync('./sources')) {
        mkdirSync('./sources')
    }

    if(!existsSync('./sources/inputRandom.cpp')) {
        const sourceData = readFileSync(path.join(__dirname,'./default/inputRandom.cpp'), 'utf-8')
        writeFileSync('./sources/inputRandom.cpp', sourceData, 'utf-8')
    }

    if(!existsSync('./sources/outputSolve.cpp')) {
        const sourceData = readFileSync(path.join(__dirname,'./default/outputSolve.cpp'), 'utf-8')
        writeFileSync('./sources/outputSolve.cpp', sourceData, 'utf-8')
    }
}

const run = async () => {
    checkExist()
    const config = require('./settings/config.json')
    const problemName = await findCPP()
    if(problemName==='!') {
        console.log(`Khong tim duoc bai tap!`)
        return
    }
    console.log(`Da phat hien bai lam: ${problemName}`)
    writeFileSync('./execute/config.txt',problemName)

    console.log(`Tao file RUN he thong!`)
    await compilieTestGen()

    console.log(`Compiling ${problemName}.CPP`)
    compilie(problemName)
    console.log(`Bien dich thanh cong!`)

    for(let i=1; i<=config.tests; i++) {
        console.log(`Dang kiem tra Test ${i}`)
        execFileSync(`inputRandom`,{"cwd":"execute"})
        execFileSync(`outputSolve`,{"cwd":"execute"})
        execFileSync(`${problemName}`,{"cwd":"execute"})

        const judgeOut = readFileSync(`./execute/sampleOutput.txt`, 'utf-8')
        const candidateOut = readFileSync(`./execute/${problemName}.OUT`, 'utf-8')

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