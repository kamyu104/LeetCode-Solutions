// Time:  O(1)
// Space: O(1)

async function sleep(millis: number): Promise<void> {
    await new Promise(resolve => setTimeout(resolve, millis));
}
