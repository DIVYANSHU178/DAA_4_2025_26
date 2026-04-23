// script.js
let stackElements = [];
let isInitialized = false;

document.getElementById('initBtn').addEventListener('click', () => {
    const size = parseInt(document.getElementById('stackSize').value);
    if (size < 1 || size > 20) {
        showMessage('Size must be between 1 and 20');
        return;
    }
    Module.ccall('initStack', null, ['number'], [size]);
    stackElements = [];
    isInitialized = true;
    updateStackDisplay();
    showMessage('Stack initialized with size ' + size);
});

document.getElementById('pushBtn').addEventListener('click', () => {
    if (!isInitialized) {
        showMessage('Initialize stack first');
        return;
    }
    const val = parseInt(document.getElementById('valueInput').value);
    if (isNaN(val)) {
        showMessage('Please enter a valid number');
        return;
    }
    Module.ccall('push', null, ['number'], [val]);
    stackElements.push(val);
    updateStackDisplay();
    showMessage('Pushed ' + val);
});

document.getElementById('popBtn').addEventListener('click', () => {
    if (!isInitialized) {
        showMessage('Initialize stack first');
        return;
    }
    const result = Module.ccall('pop', 'number', [], []);
    if (result === -1) {
        showMessage('Stack Underflow!');
    } else {
        stackElements.pop();
        updateStackDisplay();
        showMessage('Popped ' + result);
    }
});

document.getElementById('peekBtn').addEventListener('click', () => {
    if (!isInitialized) {
        showMessage('Initialize stack first');
        return;
    }
    const result = Module.ccall('peek', 'number', [], []);
    if (result === -1) {
        showMessage('Stack is empty!');
    } else {
        showMessage('Top element: ' + result);
    }
});

document.getElementById('isEmptyBtn').addEventListener('click', () => {
    if (!isInitialized) {
        showMessage('Initialize stack first');
        return;
    }
    const result = Module.ccall('isEmpty', 'boolean', [], []);
    showMessage(result ? 'Stack is empty' : 'Stack is not empty');
});

function updateStackDisplay() {
    const stackDiv = document.getElementById('stack');
    stackDiv.innerHTML = '';
    stackElements.forEach((val, index) => {
        const elem = document.createElement('div');
        elem.className = 'stack-element';
        if (index === stackElements.length - 1) {
            elem.classList.add('top');
        }
        elem.textContent = val;
        elem.style.bottom = (index * 50) + 'px';
        stackDiv.appendChild(elem);
    });
}

function showMessage(msg) {
    document.getElementById('message').textContent = msg;
    setTimeout(() => {
        document.getElementById('message').textContent = '';
    }, 3000);
}
